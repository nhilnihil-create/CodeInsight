#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<(n);++i)
using ll = long long;
using pll = pair<ll,ll>;
constexpr ll INF = (1LL<<60);
constexpr ll MOD = (1e9+7);
//constexpr ll MOD = (998244353);
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
#if loc||debg||local||debug
void dump(){cerr<<endl;}
template<class T,class... Ts> void dump(T&& h, Ts&&... t){cerr<<h<<", ";dump(forward<Ts>(t)...);}
#else
template<class T,class... Ts> void dump(T&& h, Ts&&... t){}
#endif
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T> ostream &operator<<(ostream& os,vector<T>const& v){for(auto const& vi:v)os<<(vi==INF?"_":to_string(vi))<<" ";return os;}
template<class T>vector<T> vec(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto vec(size_t a, Ts... ts){return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...));}
template<class T>vector<T> _vec(size_t a,T v){return vector<T>(a,v);}
template<class T, class... Ts>auto _vec(size_t a, Ts... ts){return vector<decltype(_vec<T>(ts...))>(a, _vec<T>(ts...));}

int main(){

  int n,m;
  cin>>n>>m;
  vector<vector<ll>> adj(n),rev(n);
  vector<ll> deg(n);
  rep(i,n-1+m){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    adj[a].emplace_back(b);
    rev[b].emplace_back(a);
    deg[b]++;
  }

  ll r = -1;
  rep(i,n)if(deg[i]==0)r=i;

  stack<ll> st;
  st.emplace(r);
  vector<ll> sorted_v;
  vector<ll> par(n,-1);
  sorted_v.reserve(n);
  while(!st.empty()){
    ll v = st.top();
    st.pop();
    sorted_v.emplace_back(v);
    for(auto nv:adj[v]){
      deg[nv]--;
      if(deg[nv]==0){
        st.emplace(nv);
        par[nv] = v;
      }
    }
  }

  rep(i,n){
    cout<<(par[i]+1)<<endl;
  }


}