#include <bits/stdc++.h>
#define int long long int
#define MOD(x) ((x % MOD_N) + MOD_N) % MOD_N
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define RFORE(i,a,b) for(int i=(b);i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SIZE(c) (int)((c).size())
#define EACH(i,v) for(auto i=v.begin();i!=v.end();++i)
#define REACH(i,v) for(auto i=v.rbegin();i!=v.rend();++i)
#define LB(c,x) distance((c).begin(),lower_bound(ALL(c),x))
#define UB(c,x) distance((c).begin(),upper_bound(ALL(c),x))
#define COUNT(c,x) (upper_bound(ALL(c),x)-lower_bound(ALL(c),x))
#define UNIQUE(c) SORT(c); (c).erase(unique(ALL(c)),(c).end());
#define COPY(c1,c2) copy(ALL(c1),(c2).begin())
#define EXIST(s,e) (bool)((s).find(e)!=(s).end())
#define PB push_back
#define MP make_pair
#define DUMP(x)  cerr<<#x<<" = "<<(x)<<endl;
#define NL cerr<<endl;
using namespace std;
template<typename T,typename U> using P=pair<T,U>;
template<typename T> using V=vector<T>;
template<typename T>bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>T sum(vector<T>&v){return accumulate(ALL(v),T());}
template<typename T>T sum(vector<T>&v,int a,int b){return accumulate(v.begin()+a,v.begin()+b,T());}
template<typename T>T max(vector<T>&v){return *max_element(ALL(v));}
template<typename T>T min(vector<T>&v){return *min_element(ALL(v));}
template<typename T>T max_index(vector<T>&v){return distance((v).begin(),max_element(ALL(v)));}
template<typename T>T min_index(vector<T>&v){return distance((v).begin(),min_element(ALL(v)));}

struct edge { int to, cost; };

template<typename T>auto&operator<<(ostream&s,const vector<T>&v){s<<"[";bool a=1;for(auto e:v){s<<(a?"":" ")<<e;a=0;}s<<"]";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const pair<T,U>&p){s<<"("<<p.first<<","<<p.second<<")";return s;}
template<typename T>auto&operator<<(ostream&s,const set<T>&st){s<<"{";bool a=1;for(auto e:st){s<<(a?"":" ")<<e;a=0;}s<<"}";return s;}
template<typename T,typename U>auto&operator<<(ostream&s,const map<T,U>&m){s<<"{";bool a=1;for(auto e:m){s<<(a?"":" ")<<e.first<<":"<<e.second;a=0;}s<<"}";return s;}

const int INF = 1e18;
const int MOD_N = 1e9+7;

signed main()
{
   int n; cin >> n;
   if (n == 3) {
      cout << "2 5 63" << endl;
      return 0;
   }
   V<int> ans;
   int i = 1;
   for (; n > 2; i++) if (i % 2 == 0 || i % 3 == 0) {
      ans.push_back(i);
      n--;
   }
   set<int> st;
   switch (sum(ans) % 6) {
      case 0:
         st.insert(2); st.insert(4);
         break;
      case 1:
         st.insert(2); st.insert(3);
         break;
      case 2:
         st.insert(4); st.insert(0);
         break;
      case 3:
         st.insert(3); st.insert(0);
         break;
      case 4:
         st.insert(2); st.insert(0);
         break;
      case 5:
         st.insert(3); st.insert(4);
         break;
   }
   for (; !st.empty(); i++) if (i % 2 == 0 || i % 3 == 0) {
      if (EXIST(st, i % 6)) {
         st.erase(i % 6);
         ans.push_back(i);
      }
   }
   REP(i, ans.size()) {
      cout << ans[i] << " ";
   }
   cout << endl;

   return 0;
}
