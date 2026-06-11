#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    if (s[i] == '1') {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}