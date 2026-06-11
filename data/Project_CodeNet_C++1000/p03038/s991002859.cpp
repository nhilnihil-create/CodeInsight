#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
 
//Write From this Line

//const ll mod = 1e9+7;
//const ll mod = 998244353;
int main()
{
	ll n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n)cin>>a[i];
	vector<int> b(m), c(m);
	rep(i,m) cin >> b[i] >> c[i];

	map<int,ll> mp;
	rep(i,n) mp[a[i]]++;

	rep(i,m){
		mp[c[i]] += b[i];
	}
	priority_queue<pair<ll,ll>> pq;
	for(auto x: mp){
		pq.push(x);
	}
	ll ans = 0;
	while(n > 0){
		auto p = pq.top(); pq.pop();
		ans += p.first * min(p.second,n);
		n -= min(n,p.second);
	}
	cout << ans << endl;
}
