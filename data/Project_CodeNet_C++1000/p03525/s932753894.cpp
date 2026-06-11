#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;using pll=pair<ll,ll>;using pld=pair<ld,ld>;
const ll INF=1LL<<60;void solve();int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();}
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d!=0&&d>0?i<n:i>n;i+=d)
#define foreach(i,A) for(auto &i:A)
#define all(A) A.begin(),A.end()
#define len(A) (ll)A.size()
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b; return 1;} return 0;}

void solve(){
  ll n; cin>>n;
  vector<ll> D(n);
  vector<ll> C(13);
  rep(i,n){
    cin>>D[i];
    C[D[i]]++;
  }

  rep(i,13){
    if(i==0 && C[i]){
      cout<<0<<"\n";
      return;
    }
    if(i==12 && C[i]>=2){
      cout<<0<<"\n";
      return;
    }
    if(C[i]>=3){
      cout<<0<<"\n";
      return;
    }
  }

  auto check=[&](ll V){
    ll score=INF;
    vector<ll> T(24,1);
    T[0]=0;
    rep(i,n){
      ll d=D[i];
      if((V>>i)&1){
        if(T[d]==0) return (ll)0;
        T[d]=0;
      }else{
        if(T[24-d]==0) return (ll)0;
        T[24-d]=0;
      }
    }
    rep(i,23){
      if(T[i+1]) T[i+1]+=T[i];
    }
    T.push_back(0);
    ll res=INF;
    rep(i,1,25){
      if(T[i]==0) chmin(res,T[i-1]);
    }
    if(res==INF) res=0;
    return res+1;
  };

  ll N=1<<n;
  ll ans=0;
  rep(V,N){
    ll score=check(V);
    chmax(ans,score);
  }

  cout<<ans<<"\n";
}