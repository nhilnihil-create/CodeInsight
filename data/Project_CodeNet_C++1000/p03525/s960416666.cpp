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

main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout<<fixed<<setprecision(10);

  ll n;
  cin>>n;
  vector<ll> a(n);
  cin>>a;

  bool zero=false;
  rep(i,n)if(a[i]==0)zero=true;
  bool three=false;
  map<ll,ll> mp;
  rep(i,n)mp[a[i]]++;
  rep(i,n)if(mp[a[i]]>=3)three=true;
  if(zero || three){
    cout<<(0)<<endl;
    return 0;
  }
  if(n==1){
    cout<<min(a[0],24-a[0])<<endl;
    return 0;
  }
  
  sort(a.begin(),a.end());
  set<ll> s={0,24};
  rep(i,n){
    if(i&1)s.insert(a[i]);
    else s.insert(24-a[i]);
  }
  auto itr=s.begin();
  ll ans=INF;
  while(*itr!=24){
    auto next=itr;
    next++;
    chmin(ans,*next-*itr);
    itr++;
  }
  cout<<(ans)<<endl;


}
