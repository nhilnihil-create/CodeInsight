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
  int n,C;
  cin>>n>>C;
  vector<vector<int>>g(1e5+100);
  vector<int>imos(1e5+100);
  set<pair<int,int>>st;
  vector<int>s(n),t(n),c(n);
  rep(i,n){
    cin>>s[i]>>t[i]>>c[i];
    st.emplace(t[i],c[i]);
  }
  rep(i,n){
    if(st.count({s[i],c[i]}))imos[s[i]]++;//同じチャンネルを連続で観ることができるかどうか
    else imos[s[i]-1]++;
    imos[t[i]]--;
  }
  int ans=1;
  rep(i,1e5+10)imos[i+1]+=imos[i],chmax(ans,imos[i+1]);
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
