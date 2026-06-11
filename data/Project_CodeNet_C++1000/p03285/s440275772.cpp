#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int X;
  cin >> X;
  int ans = 0;
  for(int i = 0; i < 200; i++) {
    for(int j = 0; j < 200; j++) { 
      if(4 * i + 7 * j == X) {
        ans++;
        cout << "Yes" << endl;
        break;
      }
    }
    if(ans == 1) {
      break;
    }
  }
  if (ans == 0) {
    cout << "No" << endl;
  }
}