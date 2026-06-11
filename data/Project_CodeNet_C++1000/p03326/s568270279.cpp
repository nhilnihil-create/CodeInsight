#include<bits/stdc++.h>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<long long> vl;
typedef std::vector<std::vector<long long>> vvl;
#define out(x) cout<<x<<"\n";
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll gcd(ll n, ll m) {
    ll tmp;
    while (m!=0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}
 
ll lcm(ll n, ll m) {
    return abs(n) / gcd(n, m)*abs(m);//gl=xy
}

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<ll> x(n), y(n), z(n);
	rep(i,n){
		cin >> x[i] >> y[i] >> z[i];
	}
	ll ans = 0;
	for (int bit = 0; bit < (1 << 3); ++bit)
	{
		vector<ll> v(n);
		if (bit & (1 << 2)){
			rep(i,n)v[i] += x[i];
		}
		else
			rep(i, n) v[i] -= x[i];
		if(bit&(1<<1)){
			rep(i, n) v[i] += y[i];
		}
		else
			rep(i, n) v[i] -= y[i];
		if(bit&(1<<0)){
			rep(i, n) v[i] += z[i];
		}
		else
			rep(i, n) v[i] -= z[i];
		sort(rall(v));
		ll sum = 0;
		rep(i, m)
		{
			sum += v[i];
		}
		chmax(ans, sum);
	}
	cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}
