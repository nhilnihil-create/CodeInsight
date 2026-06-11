#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, tmp, ans = 0;
  cin >> n >> m;

  int k[m], p[m];
  vector<int> s[m];
  for (int i = 0; i < m; i++) {
    cin >> k[i];
    for (int j = 0; j < k[i]; j++){
      cin >> tmp;
      s[i].push_back(tmp);
    }
  }

  for (int i = 0; i < m; i++)
    cin >> p[i];

  for (int tmp = 0; tmp < (1 << n); tmp++) {
    bitset<10> bs(tmp);
    int flag = 0;
    for (int i = 0; i < m; i++) { // about switch k
      int sum = 0;
      for (int j = 0; j < k[i]; j++) {
      sum += bs[s[i][j]-1];
      }
      if (sum % 2 != p[i])
        flag++;
    }
    if (flag == 0)
      ans++;
  }
  cout << ans;
  return 0;
}