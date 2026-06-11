#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<(n);++i)
using ll = int_fast64_t;
using pll = pair<ll,ll>;
constexpr ll INF = 1LL<<60;
constexpr ll MOD = 1e9+7;
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
#if loc||local
template<class T>void dump(T&& t){cerr<<t<<endl;}
template<class T,class... Ts> void dump(T&& h, Ts&&... t){cerr<<h<<", ";dump(forward<Ts>(t)...);}
#else
void dump(){}
template<class T,class... Ts> void dump(T&& h, Ts&&... t){}
#endif
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T> ostream &operator<<(ostream& os,vector<T>const& v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T,class U> ostream &operator<<(ostream& os,pair<T,U>const& p){os<<p.first<<","<<p.second;return os;}
template<class T>vector<T> vec(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto vec(size_t a, Ts... ts){return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...));}

signed main(){

  ll n,k;
  cin>>n>>k;
  vector<ll> v(n);
  cin>>v;
  auto vl = v,vr = v;
  reverse(begin(vr),end(vr));

  ll ans = 0;
  for(int l=0;l<=n;++l)for(int r=0;r<=n;++r){
    if(l+r>n)break;
    if(l+r>k)break;
    priority_queue<ll,vector<ll>,greater<>> que;
    for(int i=0;i<l;++i)que.emplace(vl[i]);
    for(int i=0;i<r;++i)que.emplace(vr[i]);
    int s = k-(l+r);
    while(s--){
      if(que.empty())break;
      if(que.top()<0)que.pop();
      else break;
    }
    ll sum = 0;
    while(!que.empty()){
      sum += que.top();
      que.pop();
    }
    chmax(ans,sum);
  }
  cout<<(ans)<<endl;

}