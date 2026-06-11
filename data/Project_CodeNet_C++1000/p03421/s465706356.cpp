#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int infint = 1e9;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)2e3 + 7;
ll n, a, b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> a >> b;
	if(a + b > n + 1 || a > n || b > n || a * b < n)
		return cout << -1, 0;
	
	for (int i = b; i >= 1; i--)
		cout << i << " ";
	
	ll q = b + 1;
	a--;
	while(q <= n)
	{
		int ptr = q;
		while(n - ptr >= a && ptr - q + 1 < b)
			ptr++;
		a--;
		for (int i = ptr; i >= q; i--)
			cout << i << " ";
		q = ptr + 1;
	}
}