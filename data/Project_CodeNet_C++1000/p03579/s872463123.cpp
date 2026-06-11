#include <bits/stdc++.h>
using namespace std;
using LL = long long;

template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

template<typename T> vector<T> make_v(size_t a) { return vector<T>(a); }
template<typename T,typename... Ts> auto make_v(size_t a,Ts... ts) { return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...)); }

template<typename T> void fill_all(T& arr, const T& v) { arr = v; }
template<typename T, typename U> void fill_all(T& arr, const U& v) { for (auto& i : arr) fill_all(i, v); }

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}
#define DUMP(x) cout<<#x<<" = "<<(x)<<endl

struct edge { int to, cost; };

const LL LINF = 1LL<<60;
const int IINF = 1LL<<30;
const LL MOD = 1e9+7;


void dfs(const auto& G, auto& V, int i, int k) {
   V[i][k] = 1;
   for (int j = 0; j < G[i].size(); ++j) {
      int to = G[i][j];
      if (V[to][(k == 0 ? 1 : 0)]) {
         continue;
      }
      dfs(G, V, to, (k == 0 ? 1 : 0));
   }
}

int main()
{
   LL n, m; cin >> n >> m;
   vector<vector<int>> G(n);
   for (int i = 0; i < m; ++i) {
      int a, b; cin >> a >> b;
      --a; --b;
      G[a].push_back(b);
      G[b].push_back(a);
   }

   auto V = make_v<int>(n, 2);

   dfs(G, V, 0, 0);

   LL a = 0, b = 0;
   for (int i = 0; i < n; ++i) {
      if (V[i][0] && !V[i][1]) ++a;
      if (!V[i][0] && V[i][1]) ++b;
   }

   LL ans = n*(n-1)/2 - a*(a-1)/2 - b*(b-1)/2 - m;
   cout << ans << endl;

   return 0;
}
