#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n;
const int MAX = 32;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  map<long long, int> cnt;
  int res = 0;
  range(i, 0, n) {
    long long a;
    cin >> a;
    cnt[a]++;
  }
  while(cnt.size()) {
    long long u = prev(cnt.end())->first;
    int c = cnt[u];
    long long v = -1;
    range(i, 0, MAX) {
      if(cnt.count((1LL << i) - u)) {
        int s = (1LL << i) - u;
        if(s != u || (s == u && c > 1)) {
          v = s;
        }
      }
    }
    if(~v) res++;
    cnt[u]--;
    if(cnt[u] == 0) cnt.erase(u);
    if(~v) {
      cnt[v]--;
      if(cnt[v] == 0) cnt.erase(v);
    }
  }
  cout << res;
  return 0;
}
