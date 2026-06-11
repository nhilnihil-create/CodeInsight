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
  ll K;
  cin >> K;
  char ans;
  for (int i = 0; i < K; i++) {
    if (S[i] == '1') {
      continue;
    }
    ans = S[i];
    cout << ans << endl;
    return 0;
  }
  ans = '1';
  cout << ans << endl;
  return 0;
}