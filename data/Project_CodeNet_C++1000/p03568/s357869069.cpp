#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main(void) {
  int n;
  cin >> n;
  int num;
  int k = 0;
  int g = 0;
  
  rep(i, n) {
    cin >> num;
    if (num % 2) {
      k++;
    } else {
      g++;
    }
  }
  int ans = pow(3, n) - pow(2, g);
  cout << ans << endl;
}

