#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;

int main() {
  ll N;
  cin >> N;
  if(N % 2 == 0) {
    cout << N << endl;
  } else {
    cout << N * 2 << endl;
  }
  return 0;
}
