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
void dump(){cerr<<endl;}
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

  int n,color;
  cin>>n>>color;
  auto d = vec<int>(color,color);
  auto c = vec<int>(n,n);
  cin>>d>>c;

  for(auto& y:c)for(auto& x:y)x--;

  vector<vector<int>> b(3);
  rep(i,n)rep(j,n){
    b[(i+j+2)%3].emplace_back(c[i][j]);
  }

  vector<vector<pair<int,int>>> uku(3);
  rep(i,3)rep(e,color){
    int tmp = 0;
    for(auto v:b[i]){
      tmp += d[v][e];
    }
    uku[i].emplace_back(tmp,e);
  }
  for(auto& vec:uku)sort(begin(vec),end(vec));

  int ans = 1<<28;
  rep(i,3)rep(j,3)rep(k,3){
    if(uku[0][i].second==uku[1][j].second)continue;
    if(uku[1][j].second==uku[2][k].second)continue;
    if(uku[0][i].second==uku[2][k].second)continue;
    ans = min(ans,uku[0][i].first+uku[1][j].first+uku[2][k].first);
  }
  cout<< ans <<endl;

/*
  vector<int> c(3);
  int ans = 1<<28;
  for(c[0]=0;c[0]<color;++c[0]){
    for(c[1]=0;c[1]<color;++c[1]){
      if(c[0]==c[1])continue;
      for(c[2]=0;c[2]<color;++c[2]){
        if(c[0]==c[2]||c[1]==c[2])continue;
        int tmp = 0;
        rep(i,n)rep(j,n){
          int x = a[i][j];
          int y = c[(i+j+2)%3];
          tmp += uku[x][y];
        }
        chmin(ans,tmp);
      }
    }
  }
  cout<<(ans)<<endl;
*/

}