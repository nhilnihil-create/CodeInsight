#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;

int maxV[40005];
int currV[40005];
void solve() {
  int n;
  cin >> n;
  int maxT = 0;
  for(int a = 0; a <= 40000; a++) maxV[a] = 1e9;
  {
    vector<int> tt, vv;
    tt.resize(n);
    vv.resize(n);
    for(int i = 0; i < n; i++) cin >> tt[i];
    for(int i = 0; i < n; i++) tt[i] *= 2;
    for(int i = 0; i < n; i++) cin >> vv[i];
    for(int i = 0; i < n; i++) vv[i] *= 2;
    int curr = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j <= tt[i]; j++) maxV[curr+j] = min(maxV[curr+j], vv[i]);
      curr += tt[i];
    }
    maxT = curr;
  }
  maxV[maxT] = 1e9;
  while(true) {
    bool upd = false;
    for(int i = 1; i < maxT; i++) {
      if(currV[i] == maxV[i]) continue;
      if(abs(currV[i] + 1 - currV[i-1]) > 1) continue;
      if(abs(currV[i] + 1 - currV[i+1]) > 1) continue;
      currV[i]++;
      upd = true;
    }
    if(!upd) break;
  }
  double ret = 0;
  for(int i = 0; i < maxT; i++) {
    ret += (currV[i] + currV[i+1]);
  }
  cout << fixed << setprecision(10) << ret/8.0 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
