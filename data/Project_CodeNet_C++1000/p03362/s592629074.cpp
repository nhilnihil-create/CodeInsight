#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 55555, M = N * N;

int n;

bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
	cin >> n;
	for (int i = 2; i <= N; i ++ )
		if (is_prime(i) && i % 5 == 1)
		{
			cout << i << ' ';
			if ( -- n == 0) break;
		}
	return 0;
}