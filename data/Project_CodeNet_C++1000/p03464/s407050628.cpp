#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
 
const int lim = 1e6 + 5;
const int Inf = 1000000007;
const long long mod = 1000000007;//998244353;
const double Pi = acos(-1);
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
long long l, r;
long long a[200005];

int main()
{
	Fastio();
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	l = 2;
	r = 2;
	for(int i = n; i >= 1; i--)
	{
		if(l > r)
		{
			cout << -1;
			return 0;
		}
		if(l % a[i] != 0)
		{
			int temp = l % a[i];
			l += (a[i] - l % a[i]);
		}
		r = r - r % a[i];
		if(l > r)
		{
			cout << "-1";
			return 0;
		}
		r += a[i] - 1;
	}
	cout << l << ' ' << r;
}