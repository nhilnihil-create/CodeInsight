#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#ifdef ENABLE_DEBUG
#define dump(a) cerr<<#a<<"="<<a<<endl
#define dumparr(a,n) cerr<<#a<<"["<<n<<"]="<<a[n]<<endl
#else
#define dump(a) 
#define dumparr(a,n) 
#endif
#define FOR(i, a, b) for(ll i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(ll i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)

typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ll,pll> ppll;
typedef vector<ll> vll;

const ll INF=(1LL<<50);
#if __cplusplus>=201700L
ll gcd(ll a, ll b) {
  if(a < b) return gcd(b, a);
  ll r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}
#endif

template<class S,class T>
std::ostream& operator<<(std::ostream& os,pair<S,T> a){
  os << "(" << a.first << "," << a.second << ")";
  return os;
}
template<class T>
std::ostream& operator<<(std::ostream& os,vector<T> a){
  os << "[ ";
  REP(a.size()){
    os<< a[i] << " ";
  }
  os<< " ]";
  return os;
}


template<typename T>
T genpow(T a,unsigned long long b){
  T base=a,ans=T(1LL);
  while(b){
    if(b&1){
      ans=ans*base;
    }
    base=base*base;
    b>>=1;
  }
  return ans;
}

pair<pll,pll> maxmin(pll a,pll b){
  return make_pair(max(a,b),min(a,b));
}
int main(){
    ll N;
    cin>>N;
    ll NN=genpow(2,N);
    vector<ll> A(NN);
    REP(NN)cin>>A[i];
    vector<pair<pll,pll>> B(NN);
    REP(NN){
      B[i]=make_pair(pll(A[i],i),pll(0,-1));
    }
    For(i,N)For(j,1<<N){
      if(j&(1<<i)){
        ll tmp=j^(1<<i);
        if(B[j].first!=B[tmp].first){
          B[j]=max(B[j],maxmin(B[j].first,B[tmp].first));
        }else{
          B[j]=max(B[j],max(maxmin(B[j].first,B[tmp].second),maxmin(B[j].second,B[tmp].first)));
        }
      }
    }
    ll mx=0;
    FOR(k,1,NN){
      mx=max(mx,B[k].first.first+B[k].second.first);
      cout<<mx<<endl;
    }
    return 0;
}
