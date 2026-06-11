#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma comment(linker, "/STACK:2000000")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'
using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 1e5 + 5, LG = 19, MOD = 998244353;
const int SQ =320;
const long double EPS = 1e-7;
int dist[N];
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  int k;
  cin >> k;

  memset(dist,63,sizeof dist);
  priority_queue<ii,vector<ii>,greater<ii>> pq;pq.push(ii(0,0));

  while(pq.size()){
      auto cur = pq.top();
      pq.pop();

      f(j,cur.S==0,10){
          if(dist[(cur.S*10+j)%k] > cur.F+j){
            dist[(cur.S*10+j)%k]=cur.F+j;
            pq.push({cur.F+j,(cur.S*10+j)%k});
          }
      }

  }

  cout << dist[0] << '\n';


  return 0;
}
