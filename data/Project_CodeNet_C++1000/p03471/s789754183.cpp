#include<iostream>
using namespace std;

int main() {
	long N, Y;
	cin >> N >> Y;
	long x, y, z, p;
	x = y = z = -1;
	p = Y / 1000;
	for (long i = 0; i <= N; i++)
	{
		for (long t = 0; t <= N - i; t++)
		{
			if (9 * i + 4 * t == p-N)
			{
				x = i;
				y = t;
				z = N - i - t;
			}
		}
	}



	cout << x << " " << y << " " << z;

	return 0;
}