#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n;
  string s;
  cin >> n >> s;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    bool count_a[26] = {0};
    bool count_b[26] = {0};
    for (int j = 0; j < i; ++j) count_a[s[j] - 'a'] = true;
    for (int j = i; j < n; ++j) count_b[s[j] - 'a'] = true;

    int tmp = 0;
    for (int i = 0; i < 26; ++i) if (count_a[i] && count_b[i]) tmp++;
    res = max(res, tmp);
  }
  cout << res << "\n";

}
