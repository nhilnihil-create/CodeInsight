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

int main()
{
   int n; cin >> n;
   vector<int> D(n);
   for (int i = 0; i < n; ++i) {
      cin >> D[i];
   }

   map<int,int> cnt;
   for (auto d : D) {
      ++cnt[d];
   }

   if (cnt[0] >= 1) {
      cout << 0 << endl;
      return 0;
   }

   for (int i = 1; i <= 11; ++i) {
      if (cnt[i] >= 3) {
         cout << 0 << endl;
         return 0;
      }
   }

   if (cnt[12] >= 2) {
      cout << 0 << endl;
      return 0;
   }

   char prev = '$';
   vector<bool> used(25, false);
   used[0] = used[24] = true;
   for (int i = 1; i <= 11; ++i) {
      if (cnt[i] == 2) {
         used[i] = true;
         used[24-i] = true;
         prev = '$';
      } else if (cnt[i] == 1) {
         if (prev == 'l') {
            prev = 'r';
            used[i] = true;
         } else {
            prev = 'l';
            used[24-i] = true;
         }
      }
      if (cnt[12] == 1) {
         used[12] = true;
      }
   }

   int count = 0, ans = 24;
   for (int i = 1; i <= 24; ++i) {
      if (used[i]) {
         chmin(ans, count+1);
         count = 0;
      } else {
         ++count;
      }
   }
   cout << ans << endl;

   return 0;
}
