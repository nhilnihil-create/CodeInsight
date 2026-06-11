#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 300010, M = 2 * N, mod = 1e9 + 7;

int n, k;

int main()
{
	cin >> n >> k;
	
	if (!k)
	{
		cout << (LL)n * n << endl;
		return 0;
	}
	
	LL res = 0;
	for (int i = k + 1; i <= n; i ++ )
	{
		res += (i - k) * (n / i);
		// cout << i << ' ' << res << ' ';
		if (n % i) res += max(n % i - k + 1, 0);
		// cout << res << endl;
	}
	cout << res << endl;
    return 0;
}
