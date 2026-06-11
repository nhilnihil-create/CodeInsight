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
#define DUMP(x) cout<<#x<<" = "<<(x)<<endl
#define COUT(x) cerr<<#x<<" = "; cout<<(x)<<endl

struct edge { int to, cost; };

const int INF = 1e18;
const int MOD = 1e9+7;

signed main()
{
   int n; cin >> n;
   string S; cin >> S;
   int Q; cin >> Q;
   vector<int> k(Q);
   for (int i = 0; i < Q; i++) {
      cin >> k[i];
   }

   for (auto K : k) {
      int a = 0, b = 0, c = 0, sum = 0;
      for (int i = 0; i < n; i++) {
         if (i-K >= 0) {
            if (S[i-K] == 'D') {
               a--; c -= b;
            } else if (S[i-K] == 'M') {
               b--;
            }
         }
         if (S[i] == 'D') {
            a++;
         } else if (S[i] == 'M') {
            b++; c += a;
         } else if (S[i] == 'C') {
            sum += c;
         }
      }
      cout << sum << endl;
   }

   return 0;
}
