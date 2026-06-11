#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll m = 1e9 + 7;

int main() {
  ll N;
  cin >> N;

  for (ll h = 1; h <= 3500; h++) {
    for (ll n = 1; n <= 3500; n++){
      if ((4*h*n-N*n-N*h) == 0) continue;
      if ((N*h*n) % (4*h*n-N*n-N*h) == 0){
        if ((N*h*n) / (4*h*n-N*n-N*h) >= 1){
          cout << h << " " << n << " " << (N*h*n) / (4*h*n-N*n-N*h) << endl;
          return 0;
        }
      }
    }
  }

  return 0;

}