#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<(n);++i)
#define reps(i,n) for(ll i=1;i<=(n);++i)
using ll = long long;
using str = string;
constexpr long long INF = (1LL<<60);
constexpr long long MOD = (1e9+7);
template<class T>inline T gcd(T a,T b){if(b==0)return a; return(gcd(b,a%b));}
template<class T>inline T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T>inline bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
inline void dump(){cout<<endl;}
template<class Head,class... Tail>inline void dump(Head&& head, Tail&&... tail){cout<<head<<", ";dump(forward<Tail>(tail)...);}
template<typename T>inline istream &operator>>(istream&input,vector<T>&v){for(auto &elemnt:v)input>>elemnt;return input;}
template<class T>vector<T> make_vec(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vec(size_t a, Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));}

main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout<<fixed<<setprecision(10);
  
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  cin>>a;
  
  vector<ll> sum(n+1);
  rep(i,n)sum[i+1]=sum[i]+a[i];
  vector<ll> sub;
  rep(i,n){
    for(ll j=i;j<n;++j){
      sub.emplace_back(sum[j+1]-sum[i]);
    }
  }

  auto f = [&](ll a)->bool{
    ll cnt=0;
    for(const auto& x:sub){
      if((x&a)==a)cnt++;
    }
    return cnt>=k;
  };

  ll ans=0;
  for(ll i=45;i>=0;--i){
    if( f(ans|(1LL<<i)) ){
      ans|=(1LL<<i);
    }
  }
  cout<<(ans)<<endl;


}
