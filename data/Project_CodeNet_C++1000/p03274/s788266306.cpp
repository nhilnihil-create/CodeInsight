#include<algorithm>
#include<cmath>
#include<climits>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
	int N, K;
	cin >> N >> K;

	vector<ll> x(N);
	rep(i, N) cin >> x[i];

	auto start = lower_bound(all(x), 0);

	if (start == x.begin())
	{
		cout << x[K - 1] << endl;
	}
	else if (start == x.end())
	{
		cout << abs(x[N - K]) << endl;
	}
	else
	{
		vector<ll> xl = vector<ll>(x.begin(), start);
		if (xl.back() != 0) xl.push_back(0);
		reverse(all(xl));

		vector<ll> xr;
		if (*start != 0) xr.push_back(0);
		xr.insert(xr.end(), start, x.end());

		ll ans = 100000000000000000;

		reple(i, 0, K)
		{
			if (i < xl.size() && (K - i) < xr.size())
			{
				ll l = abs(xl[i]);
				ll r = abs(xr[K - i]);
				chmin(ans, l + r + min(l, r));
			}
		}

		cout << ans << endl;
	}

	return 0;
}