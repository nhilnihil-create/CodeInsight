#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <deque>

using namespace::std;

int ri()
{
	int x;
	scanf("%d", &x);

	return x;
}

int64_t ri64()
{
	int64_t x;
	scanf("%lld", &x);

	return x;
}

void wi(int x)
{
	printf("%d\n", x);
}

void wvi(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
}

void dbg(string &str, int x)
{
	cout << str << ": ";
	wi(x);
}

void dbg(string &str, vector<int> &x)
{
	cout << str << ": ";
	wvi(x);
}

int main()
{
	int64_t N = ri();
	int64_t X = ri64();

	vector<int64_t> A(N);
	for (int i = 0; i < N; i++)
		A[i] = ri64();

	vector<int64_t> S(N, 0);
	for (int i = 0; i < N; i++)
	{
		S[i] = A[i];
		if (i > 0)
			S[i] += S[i - 1];
	}

	int64_t ans = -1;
	for (int64_t k = 1; k <= N; k++)
	{
		int64_t s = k * X;
		
		s += 2 * S[N - 1];
		if (k < N)
			s -= 2 * S[N - 1 - k];	
		
		int64_t c = 3;
		int64_t t = N - 1;

		while (t >= 0)
		{
			if (ans != -1 && s > ans)
				break;			

			s += c * S[t];

			t -= k;			
			if (t >= 0)
				s -= c * S[t];

			c += 2;
		} 
		
		if (ans == -1 || ans > s)
			ans = s;
	}	

	ans += N * X;
	cout << ans << endl;

	return 0;
}
