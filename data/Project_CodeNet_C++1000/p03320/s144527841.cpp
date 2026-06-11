#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const double INF = 1e20;

int K, cnt = 1;
long long N = 1, pow[20];

void init()
{
	pow[0] = 1;
	for (int i = 1; i < 20; i++)
		pow[i] = pow[i - 1] * 10;	
}

double sum(long long v)
{
	int ret = 0;
	while (v)
		ret += v % 10, v /= 10;	
	return ret;
}

long long f(long long n)
{
	double mn = INF;
	long long x = n, y = n, ret = n;
	int p = 0;
	while (x >= 10)
	{
		int z = x % 10;
		while (z < 9)
			z++, y += pow[p];
		double now = y / sum(y);
		if (now < mn)
			mn = now, ret = y;
		x /= 10, p++;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> K;
	init();
	while (cnt <= K)
	{
		cout << N << endl;
		N = f(N + 1);
		cnt++;
	}
	return 0;
}
