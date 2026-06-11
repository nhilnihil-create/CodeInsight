#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string S;
  cin >> S;
  vector<bool> is_found(26, false);
  for (int i = 0; i < S.length(); i++) {
    is_found[S[i] - 'a'] = true;
  }
  vector<char> availables;
  for (int i = 0; i < 26; i++) {
    if (!is_found[i]) availables.push_back(i + 'a');
  }
  string ans = "-1";
  if (S.length() < 26) {
    ans = S + availables[0];
    cout << ans << endl;
    return 0;
  }
  for (int i = S.length() - 1; i >= 0; i--) {
    char replace_char = -1;
    for (int j = 0; j < availables.size(); j++) {
      if (S[i] < availables[j]) {
        replace_char = availables[j];
        break;
      }
    }
    if (replace_char != -1) {
      ans = S.substr(0, i);
      ans += replace_char;
      break;
    } else {
      availables.push_back(S[i]);
      sort(availables.begin(), availables.end());
    }
  }
  cout << ans << endl;
  return 0;
}