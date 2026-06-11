// review
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 51;

int n;
int d[MAXN];

int calc(vector<int>& v) {
  int diff = 24;
  sort(v.begin(), v.end());
  for (int i=0;i<v.size()-1;i++) {
    diff = min(v[i + 1] - v[i], diff);
  }
  return diff;
}

void solve() {
  map<int, int> m;
  for (int i=0;i<n;i++) {
    m[d[i]]++;
    if (m[d[i]] > 2) {
      cout << 0 << endl;
      return;
    }
  }

  if (m[0] > 0 || m[12] > 1) {
    cout << 0 << endl;
    return;
  }

  int cnt = 0;
  for (int i=0;i<(1<<11);i++) {
    vector<int> v;
    v.push_back(0);
    v.push_back(24);
    for (int j=1;j<=11;j++) {
      if (m[j] == 2) {
        v.push_back(j);
        v.push_back(24 - j);
      } else if (m[j] == 1) {
        if ((i >> (j-1)) & 1) {
          v.push_back(j);
        } else {
          v.push_back(24 - j);
        }
      }
    }
    if (m[12] > 0) {
      v.push_back(12);
    }
    cnt = max(cnt, calc(v));
  }
  cout << cnt << endl;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> d[i];
  }
  solve();
}
