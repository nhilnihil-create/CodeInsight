#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  int ans;
  for(int i = 1; i <= (int)sqrt(n); i++) {
    if(i * i <= n) {
      ans = i * i;
    }
  }
  cout << ans << endl;
}
