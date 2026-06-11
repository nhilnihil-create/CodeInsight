#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int N;
  cin >> N;
  vector<P> ans;
  for (int i = 1; i <= N; i++) {
    for (int j = i+1; j <= N; j++) {
      if (i == j || i + j == ((N/2) * 2) + 1) {
        continue;
      } else {
        ans.push_back(make_pair(i,j));
      }
    }
  }
  cout << (int)ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}