#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
// https://task4233.hatenablog.com/entry/2018/08/16/222107

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main() {
  int N;
  cin >> N;
  vector<double> t(N), v(N);
  for (int i = 0; i < N; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }

  int T = 0;
  for (int i = 0; i < N; i++) {
    T += t[i];
  }

  vector<double> maxV(2 * T + 1, (double) INF);
  int nowT = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < t[i]; j++) {
      int t1 = nowT + j * 2;
      int t2 = nowT + j * 2 + 1;
      maxV[t1] = min(maxV[t1], v[i]);
      maxV[t2] = min(maxV[t2], v[i]);
    }
    nowT += t[i] * 2;
    maxV[nowT] = min(maxV[nowT], v[i]);
  }

  maxV[0] = maxV[2 * T] = 0.0;

  for(int i = 0; i < 2 * T + 1; i++) {
    maxV[i + 1] = min(maxV[i + 1], maxV[i] + 0.5);
  } 

  for (int i = 2 * T; i >= 0; i--) {
    maxV[i] = min(maxV[i], maxV[i + 1] + 0.5);
  }

  double ans = 0.0;
  for (int i = 0; i <  2 * T + 1; i++) {
    ans += (maxV[i] + maxV[i + 1]) * 0.5 / 2.0;
  }
  cout << fixed << ans << endl;

  return 0;
}
