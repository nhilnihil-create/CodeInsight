#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,K;
  cin >> N >> K;
  int ans = 0;
  int cnt = 0;
  while (cnt < N) {
    if (ans == 0) {
      cnt += K;
    } else {
      cnt += K-1;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}