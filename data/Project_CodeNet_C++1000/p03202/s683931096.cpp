#include <bits/stdc++.h>
#define int long long int
using namespace std;
template<typename T,typename U> using P=pair<T,U>;
template<typename T> using V=vector<T>;
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}
#define DUMP(x)  cerr<<#x<<" = "<<(x)<<endl;

struct edge { int to, cost; };

const int INF = 1e18;
const int MOD = 1e9+7;

bool is_possible(const V<int>& a, int k) {
   int n = a.size();
   stack<P<int,int>> st;
   for (int i = 1; i < n; i++) {
      if (a[i-1] < a[i]) continue;
      while (!st.empty() && st.top().first > a[i]) {
         st.pop();
      }
      if (!st.empty() && st.top().first == a[i]) {
         st.top().second++;
      } else {
         st.push(make_pair(a[i], 1));
      }

      while (st.top().second == k) {
         int id = st.top().first;
         if (id == 1) {
            return false;
         }
         st.pop();
         if (!st.empty() && st.top().first == id - 1) {
            st.top().second++;
         } else {
            st.push(make_pair(id - 1, 1));
         }
      }
   }
   return true;
}

signed main()
{
   int n; cin >> n;
   V<int> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   bool all_increacing = true;
   for (int i = 1; i < n; i++) {
      if (a[i] <= a[i-1]) {
         all_increacing = false;
         break;
      }
   }
   if (all_increacing) {
      cout << 1 << endl;
      return 0;
   }

   int l = 1, r = n;
   while (r - l > 1) {
      int m = (l + r) / 2;
      if (is_possible(a, m)) {
         r = m;
      } else {
         l = m;
      }
   }
   cout << r << endl;

   return 0;
}
