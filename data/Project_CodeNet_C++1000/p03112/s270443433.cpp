#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#include<random>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

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
	return abs(n * m) / gcd(n, m);//gl=xy
}
 
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
 
using namespace std;
//ここから

void solve(){
  int a,b,q;
  cin>>a>>b>>q;
  vector<ll>s(a),t(b);
  ll x;
  rep(i,a)cin>>s[i];
  rep(i,b)cin>>t[i];
  rep(i,q){
    cin>>x;
    ll ans=INF;
    int sr=lower_bound(all(s),x)-s.begin();
    int tr=lower_bound(all(t),x)-t.begin();
    int sl=max(0,sr-1);
    int tl=max(0,tr-1);
    chmin(sr,a-1);
    chmin(tr,b-1);
    chmin(ans,abs(s[sl]-t[tl])+min(abs(x-s[sl]),abs(x-t[tl])));
    chmin(ans,abs(s[sl]-t[tr])+min(abs(x-s[sl]),abs(x-t[tr])));
    chmin(ans,abs(s[sr]-t[tl])+min(abs(x-s[sr]),abs(x-t[tl])));
    chmin(ans,abs(s[sr]-t[tr])+min(abs(x-s[sr]),abs(x-t[tr])));
    cout<<ans<<"\n";
  }
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
