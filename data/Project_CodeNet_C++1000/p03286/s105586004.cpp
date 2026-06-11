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

template<typename T>
vector<T>base_conversion(T n,T base){
  vector<T>res;
  while(abs(n)>=1){
    T x=n%base;
    n/=base;
    if(x<0){
      x+=abs(base);//余りが負となるのを補正
      n++;//余りを調整したので,商を調整
    }
    res.push_back(x);
  }
  if(res.empty())res.push_back(0);
  reverse(res.begin(),res.end());
  return res;
}


void solve(){
  ll n;
  cin>>n;
  for(auto d:base_conversion<ll>(n,-2LL))cout<<d;
  
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}
