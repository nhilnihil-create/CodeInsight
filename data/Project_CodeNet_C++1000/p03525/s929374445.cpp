#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0;i<(n);++i)
#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; cin >> N;

  map<int, int> m;
  ++m[0];
  rep(i, N) {
    int d; cin >> d;
    ++m[min(d, 24-d)];
  }
  vector<int> v, v2;
  rep(i, 13) {
    if (m[i] == 0)
      continue;
    if (m[i] >= 3) {
      out(0);
      return 0;
    }
    if (m[i] == 2) {
      if (i == 24 - i || i == 0) {
        out(0);
        return 0;
      }
      v2.push_back(i);
      v2.push_back(24-i);
    } else {
      v.push_back(i);
    }
  }
  sort(all(v));
  rep(i, v.size()) {
    if (i % 2 != 0)
      v2.push_back(24-v[i]);
    else
      v2.push_back(v[i]);
  }
  sort(all(v2));
  int ans = 100;
  rep(i, v2.size()-1) {
    ans = min(ans, v2[i+1] - v2[i]);
  }
  ans = min(ans, v2[0] - v2.back() + 24);
  out(ans);

  return 0;
}
