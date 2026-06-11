#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
/*
int maximum(int* x, int N)
{
	int M = 0;
	for (int i = 0; i < N; i++)
		M = (M > x[i] ? M : x[i]);
	return M;
}
int minimum(int* x, int N)
{
	int m = 0;
	for (int i = 0; i < N; i++)
		m = (m < x[i] ? m : x[i]);
	return m;
}*/
int height(int x, int y, int x_pot, int y_pot, int H_pot)
{
	int h;
	h = max(H_pot - abs(x - x_pot) - abs(y - y_pot), 0);
	return h;
}

int main()
{
	/*---Read Parameters-----*/
	int N;
	cin >> N;
	int* x = new int[N];
	int* y = new int[N];
	long long* h = new long long[N];
	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i] >> h[i];
	/*---Read Parameters: Completed-----*/
	/*-----Try every (x, y) for the centre-----*/
	//for (int i = 0; i < N; i++)
	//	cout << x[i] << ' ' << y[i] << ' ' << h[i] << '\n';
	int xc = 0, yc = 0;
	long long H = 0;
	//putchar('\n');
	for (int x_pot = 0; x_pot <= 100; x_pot++)
	{
		//printf("x_pot = %d\t", x_pot);
		bool larger_flag = false;
		for (int y_pot = 0; y_pot <= 100; y_pot++)
		{
			//printf("y_pot = %d\n", y_pot);
			long long H_pot = 1;	//pot means "potential".
			for (int n = 0; n < N; n++)	//To find the potential H_pot, and that requires an h != 0.
				if (h[n] != 0)	//And if no h != 0 is in the array, H_pot will be considered 1.
				{
					//cout << h[n] << ' ' << n;
					H_pot = h[n] + abs(x[n] - x_pot) + abs(y[n] - y_pot);
					break;
				}
			bool flag = true;
			for (int n = 0; n < N; n++)
				if (h[n] != height(x[n], y[n], x_pot, y_pot, H_pot))
				{
					flag = false;
					break;
				}
			if (flag == true)
			{
				larger_flag = true;
				yc = y_pot;
				H = H_pot;
				break;
			}
		}
		if (larger_flag == true)
		{
			xc = x_pot;
			break;
		}
	}
	std::cout << xc << ' ' << yc << ' ' << H;
	getchar(); getchar();
	return 0;
}

//Ref: https://blog.csdn.net/qq_33241119/article/details/82954937