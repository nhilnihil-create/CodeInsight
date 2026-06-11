#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int N;
  cin >> N;
  vector<int> b(N);
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < N; i++) {
    bool can = false;
    for (int j = b.size() - 1; j >= 0; j--) {
      if (b[j] == j+1) {
        b.erase(b.begin()+j);
        ans.push_back(j+1);
        can = true;
        break;
      }
    }
    if (!can) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = ans.size()-1; i>= 0; i--) {
    cout << ans[i] << endl;
  }
  return 0;
}