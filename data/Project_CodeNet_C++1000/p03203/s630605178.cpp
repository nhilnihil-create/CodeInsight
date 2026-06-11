#include <bits/stdc++.h>
#define dbg(x) cerr << ">>> " << x << endl
#define _ << ", " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<int> wtf[ms];

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int h, w, n;
  std::cin >> h >> w >> n;
  int ans = h;
  for(int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    wtf[x].push_back(y);
  }
  int best = 1;
  for(int i = 2; i <= h; i++) {
    std::sort(wtf[i].begin(), wtf[i].end());
    int nxtBest = best + 1;
    for(auto t : wtf[i]) {
      if(t <= best) {
        ans = std::min(ans, i - 1);
      }
      if(t == best + 1) nxtBest = best;
    }
    best = nxtBest;
  }
  std::cout << ans << '\n';
  return 0;
}