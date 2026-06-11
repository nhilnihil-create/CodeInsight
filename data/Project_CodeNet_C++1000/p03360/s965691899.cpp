#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
  vector<ll> abc(3);
  ll K;
  rep(i,3) cin >> abc.at(i);
  sort(abc.begin(), abc.end());
  cin >> K;
  ll res = pow(2, K) * abc[2] + abc[1] + abc[0];
  cout << res << endl;
}
