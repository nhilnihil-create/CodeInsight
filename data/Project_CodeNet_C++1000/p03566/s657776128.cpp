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
  int n;
  cin>>n;
  vector<double>t(n+1),v(n+1);
  vector<double>S;
  double sum_t=0;
  rep(i,n){
    cin>>t[i+1];
    t[i+1]+=t[i];
  }
  sum_t=t.back();
  rep(i,n){
    cin>>v[i];
  }
  auto func=[&](double cur,double left,double right,double velocity)->double{//最大の速度を返す
    if(left<=cur&&cur<=right)return velocity;
    else if(right<cur)return velocity+(cur-right);
    else return velocity+(left-cur);
  };
  for(double i=0;i<=sum_t;i+=0.5){
    double vv=1e9;
    rep(j,n){
      chmin(vv,func(i,t[j],t[j+1],v[j]));
    }
    chmin(vv,i);//始点からの影響
    chmin(vv,sum_t-i);//終点からの影響
    S.pb(vv);
  }
  double ans=0;
  rep(i,S.size()-1){
    ans+=(S[i]+S[i+1])*0.25;
  }
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}