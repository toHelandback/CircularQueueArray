#include <iostream>
#include <string>
using namespace std;
template<class T>
class CircularQueue
{
private:
	T *arr;
	int size, front, rear, cap;
public:
	CircularQueue(int size);
	bool isEmpty();
	bool isFull();
	void Enqueue(T val);
	void Dequeue(T &val);
	T frontval();
	T rearval();

};
template<class T>
CircularQueue<T>::CircularQueue(int size)
{
	this->size = size;
	arr = new T[size];
	cap = front = rear = 0;
}
template<class T>
bool CircularQueue<T>::isEmpty()
{
	if (cap == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
bool CircularQueue<T>::isFull()
{
	if (cap == size)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<class T>
void CircularQueue<T>::Enqueue(T val)
{
	if (!isFull())
	{
		cap++;
		arr[rear] = val;
		rear++;
		rear = rear % size;
	}
	else
	{
		return;
	}
}
template<class T>
void CircularQueue<T>::Dequeue(T &val)
{
	if (!isEmpty())
	{
		cap--;
		val = arr[front];
		front++;
		front = front % size;
	}
}
template<class T>
T CircularQueue<T>::frontval()
{
	if (!isEmpty())
	{
		return arr[front];
	}
	else
	{
		return T();
	}
}
template<class T>
T CircularQueue<T>::rearval()
{
	if (!isEmpty())
	{
		return arr[rear - 1];
	}
	else
	{
		return T();
	}
}
// Driver Program
int main()
{
	CircularQueue<int> q(5);
	q.Enqueue(10);
	q.Enqueue(20);
	int val = 0;
	q.Dequeue(val);
	cout << val << endl;
	q.Dequeue(val);
	cout << val << endl;
}


