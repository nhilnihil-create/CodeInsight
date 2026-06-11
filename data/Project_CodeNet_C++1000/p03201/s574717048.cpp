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
	ll n;
	cin>>n;
	vector<ll>a(n);
	rep(i,n)cin>>a[i];
	sort(rall(a));
	map<ll,ll>mp;
	rep(i,n)mp[a[i]]++;
	int ans=0;
	rep(i,n){
		if(!mp.count(a[i]))continue;
		rep(j,30){
			ll x=1LL<<(30-j);
			if(x-a[i]<a[i])break;
			if(mp.count(x-a[i])){
				if(x-a[i]==a[i]&&mp[a[i]]==1)continue;
				mp[x-a[i]]--;
				mp[a[i]]--;
				if(mp[x-a[i]]==0)mp.erase(x-a[i]);
				if(mp[a[i]]==0)mp.erase(a[i]);
				++ans;
				break;
			}
		}
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
