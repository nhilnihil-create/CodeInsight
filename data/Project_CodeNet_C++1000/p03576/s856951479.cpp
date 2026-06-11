#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
    
int main()
{
  int N,K;
  cin >> N >> K;
  vector<ll> x(N), y(N), xc(N), yc(N);
  REP(i,N){
    cin >> x[i] >> y[i];
  	xc[i] = x[i];
    yc[i] = y[i];
  }
  sort(ALL(xc));
  sort(ALL(yc));
  ll ans = (1LL<<63)-1;
  REP(i,N){
    int x1 = xc[i];
    FOR(j,i+1,N){
      int x2 = xc[j];
      REP(k,N){
        int y1 = yc[k];
        FOR(l,k+1,N){
          int y2 = yc[l];
          int cnt = 0;
          REP(p,N){
            if(x1 <= x[p] && x[p] <= x2 && y1 <= y[p] && y[p] <= y2) cnt++;
          }
          if(cnt>=K) ans = min(ans,(xc[j]-xc[i])*(yc[l]-yc[k]));
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}