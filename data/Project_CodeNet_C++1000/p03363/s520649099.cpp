#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i, a) for (int i = (int)0; i < (int)a; ++i)
#define rrep(i, a) for (int i = (int)a - 1; i >= 0; --i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RREP(i, a, b) for (int i = (int)a - 1; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define popcount __builtin_popcount
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
template <class T>
inline bool chmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

ll gcd(ll n, ll m)
{
	ll tmp;
	while (m != 0)
	{
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m)
{
	return abs(n) / gcd(n, m) * abs(m); //gl=xy
}

using namespace std;
//using namespace atcoder;

void solve(){
	int n;
	cin>>n;
	vector<ll>a(n);
	rep(i,n)cin>>a[i];
	map<ll,ll>mp;
	vector<ll>sum(n+1);
	rep(i,n)sum[i+1]=sum[i]+a[i];
	rep(i,n+1){
		mp[sum[i]]++;
	}
	ll ans=0;
	rep(i,n+1){
		mp[sum[i]]--;
		ans+=mp[sum[i]];
	}
	cout<<ans<<"\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}
