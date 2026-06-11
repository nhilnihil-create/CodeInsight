#include <bits/stdc++.h>
#include <cmath>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
typedef vector<ll> V;
typedef vector<V> VV;
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return 1;
	}
	return 0;
}
const long long INFLL = 1LL << 60;
const int INF = 1 << 28;
void solve(int a) { cout << (a ? "Yes" : "No") << endl; }
int main()
{
	ll n;
	long long ans = 0LL;
	cin >> n;
	for (int i = 1; i <= sqrt(n) + 3; i++)
	{
		if (n % i == 0)
		{
			if(n/i >1){
			if (i == n % ((n / i) - 1))
			{
				ans += ((n / i) - 1);
			}
			}
			//	cout<<((n/i)-1)<<endl;
		}
	}
	cout << ans << endl;
}
