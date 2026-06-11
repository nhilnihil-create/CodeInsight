#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
#include<chrono>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define vint(a,n) vint a(n); rep(i, n) cin >> a[i];
#define vll(a,n) vll a(n); rep(i, n) cin >> a[i];
#define ALL(n) begin(n),end(n)
#define RALL(n) rbegin(n),rend(n)
#define MOD (1000000007)
// #define MOD (998244353)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
using vbool=vector<bool>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pl(T x){cout << x << " ";}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
// 全頂点から各点への最短距離を求める。O(V^3)
void warshall_floyd(arr<int>& d) {
   int n = d.size();
    for (int k = 0; k < n; k++){       // 経由する頂点
      for (int i = 0; i < n; i++) {    // 始点
        for (int j = 0; j < n; j++) {  // 終点
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }
int main()
{
    int h, w; cin >> h >> w;
    arr<int> d(10, vector<int>(10, 0));
    rep(i, 10) rep(j, 10) cin >> d[i][j];
    warshall_floyd(d);

    ll ans = 0;
    rep(i, h) rep(j, w){
        int a; cin >> a;
        if(a==1 || a==-1) continue;
        ans += d[a][1];
    }
    pr(ans);
    return 0;}