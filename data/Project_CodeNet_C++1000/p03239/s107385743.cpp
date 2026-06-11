#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N, T;
  cin >> N >> T;
  int MI, X, Y;
  MI = 10000;
  rep(i, N) {
    cin >> X >> Y;
    if(Y <= T) {
      MI = min(X, MI);
    }
  }
  if(MI == 10000) {
    cout << "TLE" << endl;
  }
  else {
    cout << MI << endl;
  }
}