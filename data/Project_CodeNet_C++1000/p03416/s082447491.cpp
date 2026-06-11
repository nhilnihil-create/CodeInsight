#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int ans = B - A + 1;
  for (int i = A; i <= B; i++) {
    string s = to_string(i);
    int j = 0, k = s.size() - 1;
    while (j <= k) {
      if (s.at(j) == s.at(k)) {
        j++;
        k--;
      } else {
        ans--;
        break;
      }
    }
  }
  cout << ans;
}
