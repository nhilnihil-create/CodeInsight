#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

int main(){
  int N;
  cin >> N;
  vector<double> T(N), V(N), dist(101, -1);
  dist[0] = 0;
  REP(i, N) { cin >> T[i]; }
  REP(i, N) { cin >> V[i]; }
  REP(i, N) {
    REP(j, T[i]) {
      vector<double> ndist(101, -1);
      REP(ps, V[i]+1) {
        for(int s = ps-1; s <= ps+1; ++s) {
          if(s < 0 || s > V[i] || dist[s] < 0) continue;
          double tdist = dist[s] + (s + ps) * 0.5 + (s == ps && s < V[i] ? 0.25 : 0);
          ndist[ps] = max(tdist, ndist[ps]);
        }
      }
      dist = ndist;
    }
  }
  cout << fixed << setprecision(9) << dist[0] << endl;
}