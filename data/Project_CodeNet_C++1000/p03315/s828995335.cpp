#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    if (S[i] == '+') {
      ans++;
    } else {
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}