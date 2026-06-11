#include <bits/stdc++.h>
#define int long long int
using namespace std;
template<typename T,typename U> using P=pair<T,U>;
template<typename T> using V=vector<T>;
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

const int INF = 1LL<<60;
const int MOD = 1e9+7;

signed main()
{
   int a,b,c; cin >> a >> b >> c;
   if (a == b && b == c && c == a) {
      cout << "Yes" << endl;
   } else {
      cout << "No" << endl;
   }

   return 0;
}
