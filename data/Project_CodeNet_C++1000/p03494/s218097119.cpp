#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n, a, d;
  int ans = 100;
  cin >> n;
  rep(i, n) {
    d = 0;
    cin >> a;
    while (a % 2 == 0) {
      a /= 2;
      d++;
    }
    if (d < ans) ans = d;
  }
  cout << ans << endl;
}
