// g++ A.cpp -Wall -Wextra -Woverflow -Wshadow -O2
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>
#include <bitset>

using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;

const int MAXB = 21;
int node[MAXB];

int main() {
  ios::sync_with_stdio(false);
  int L;
  cin >> L;
  L--;
  vector<edge> ans;
  int maxbit = 0;
  for (int i = 0; i < MAXB; i++) {
    if (1 << (i + 1) > L) {
      maxbit = i;
      break;
    }
  }
  int num = 2;
  if (L == (1 << (maxbit + 1)) - 1) {
    ans.push_back(edge(1 << maxbit, pii(1, 2)));
    ans.push_back(edge(0, pii(1, 2)));
    node[maxbit] = num - 1;
    num++;
  }
  for (int j = maxbit - 1; j >= 0; j--) {
    ans.push_back(edge(1 << j, pii(num - 1, num)));
    ans.push_back(edge(0, pii(num - 1, num)));
    node[j] = num - 1;
    num++;
  }
  num--;

  if (L != (1 << (maxbit + 1)) - 1) {
    int cur = 0;
    for (int i = maxbit; i >= 0; i--) {
      if (!(L & (1 << i))) continue;
      cur |= (1 << i);
      L ^= (1 << i);

      int tot = 0;
      bool done = 0;
      for (int j = 0; j <= maxbit; j++) {
        if (tot + (1 << j) > L) {
          j--;
          if (j < 0) ans.push_back(edge(cur, pii(1, num)));
          else ans.push_back(edge(cur, pii(1, node[j])));
          break;
        } else if (tot + (1 << j) == L) {
          done = 1;
          ans.push_back(edge(cur, pii(1, node[j])));
          break;
        }
        tot += (1 << j);
      }
      if (done) break;
    }
  }

  cout << num << ' ' << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].second.first << ' ' << ans[i].second.second << ' ' << ans[i].first << '\n';
  }
} 