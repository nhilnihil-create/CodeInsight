#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)

const ll INF=1LL<<29;

signed main() {
  int h,w;
  cin >> h >> w;
  int c[10][10];
  rep(i,10) rep(j,10) cin >> c[i][j];
  rep(k,10) rep(i,10) rep(j,10) c[i][j] = min(c[i][j], c[i][k] + c[k][j]); 

  int ans = 0;
  rep(i,h) rep(j,w) {
    int a; cin >> a;
    if(a !=-1) ans += c[a][1];
  }
  cout << ans << endl;
}
