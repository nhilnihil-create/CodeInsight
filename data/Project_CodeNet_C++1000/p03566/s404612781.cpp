#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

typedef int64_t ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;

int main(){
  int N;
  cin >> N;
  vector<int> t(N), v(N);
  REP(i, N) cin >> t[i];
  REP(i, N) cin >> v[i];

  vector<int> tcum(N + 1, 0);
  REP(i, N) tcum[i + 1] = tcum[i] + t[i];
  int T = tcum[N];

  vector<ld> vmax(2 * T + 1, INF);
  REP(i, 2 * T + 1) {
    ld time = 0.5 * i;
    vmax[i] = min(vmax[i], min(time, T - time));
  }
  REP(i, N) {
    REP(j, 2 * T + 1) {
      ld time = 0.5 * j;
      if(time > tcum[i + 1]) {
        vmax[j] = min(vmax[j], v[i] + time - tcum[i + 1]);
      }else if(time >= tcum[i]) {
        vmax[j] = min(vmax[j], (ld)v[i]);
      }else{
        vmax[j] = min(vmax[j], v[i] + tcum[i] - time);
      }
    }
  }

  ld ret = 0;
  REP(i, 2 * T) {
    ret += 0.25 * (vmax[i] + vmax[i + 1]);
  }

  cout << fixed << setprecision(10) << ret << endl;
  return 0;
}

