#include <bits/stdc++.h>
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


void solve()
{
	int n;
	cin>>n;
	vector<ll>a(n);
	rep(i,n)cin>>a[i];
	ll sum=0;
	rep(i,n)sum+=a[i];
	ll left_l=a[0],left_r=a[1],right_l=0,right_r=0;
	int pos_l=1,pos_r=0;
	for(int i=2;i<n;++i){
		right_r+=a[i];
	}
	ll minv=INF;
	ll x,y;
	for(int i=2;i<n-1;++i){
		right_l+=a[i];
		right_r-=a[i];
		if(chmin(minv,abs(right_l-right_r))){
			x=right_l,y=right_r;
			pos_r=i+1;
		}
	}
	right_l=x,right_r=y;
	ll ans=0;
	ans=max({left_l,left_r,right_l,right_r})-min({left_l,left_r,right_l,right_r});
	for(int i=2;i<n-2;++i){
		left_r+=a[i];
		right_l-=a[i];
		ll min_l=abs(left_r-left_l),min_r=abs(right_r-right_l);
		while(pos_l<i&&chmin(min_l,abs((left_r-a[pos_l])-(left_l+a[pos_l])))){
			left_r-=a[pos_l];
			left_l+=a[pos_l];
			++pos_l;
		}
		while(pos_r<n-1&&chmin(min_r,abs((right_r-a[pos_r])-(right_l+a[pos_r])))){
			right_r-=a[pos_r];
			right_l+=a[pos_r];
			++pos_r;
		}
		//cout<<left_l<<" "<<left_r<<" "<<right_l<<" "<<right_r<<"\n";
		chmin(ans,max({left_l,left_r,right_l,right_r})-min({left_l,left_r,right_l,right_r}));
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
