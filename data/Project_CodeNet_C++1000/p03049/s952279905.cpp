#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int N;
  cin >> N;
  string s[N];
  int a = 0;
  int b = 0;
  int c = 0;
  int ans = 0;
  for (int i= 0; i < N; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < N; i++) {
    if (s[i][0] == 'B' && s[i][s[i].size()-1] == 'A') {
      c++;
    } else if (s[i][0] == 'B') {
      b++;
    } else if (s[i][s[i].size()-1] == 'A') {
      a++;
    }
    for (int j = 1; j < s[i].size(); j++) {
      if (s[i][j-1] == 'A' && s[i][j] == 'B') {
        ans++;
      }
    }
  }
  int ab = min(a,b);
  if (ab >= 1) {
    ans += ab + c;
  } else if (a == 0 && b != 0) {
    ans += c;
  } else if (a != 0 && b == 0) {
    ans += c;
  } else if (a == 0 && b == 0 && c != 0) {
    ans += c-1;
  } else if (c == 0) {
    ans += 0;
  } 
  cout << ans << endl;
  return 0;
}
