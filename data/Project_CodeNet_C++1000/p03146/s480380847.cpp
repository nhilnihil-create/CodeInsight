#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int s;
  cin >> s;
  map<int,bool> mp;
  int cnt = 0;
  while (0 == 0) {
    if (mp[s] == true) {
      break;
    }
    mp[s] = true;
    if (s % 2 == 0) {
      s /= 2;
    } else {
      s = (3 * s) + 1;
    }
    cnt++;
  }
  cout << cnt+1 << endl;
  return 0;
}