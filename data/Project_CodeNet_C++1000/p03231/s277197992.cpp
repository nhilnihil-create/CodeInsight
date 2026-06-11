#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  string T;
  cin >> T;
  ll lcm = N * M / __gcd(N, M);
  map<ll, char> X;
  ll cnt = 0;
  while (lcm / M * cnt < lcm) {
    X[lcm / M * cnt] = T[cnt];
    cnt += 1;
  }
  cnt = 0;
  while (lcm / N * cnt < lcm) {
    if (X[lcm / N * cnt] == '\0') {
      cnt += 1;
      continue;
    }
    else {
      if (X[lcm / N * cnt] != S[cnt]) {
        cout << "-1" << "\n";
        // cout << S[cnt] << ' ' << X.at(lcm / N * cnt) << "\n";
        return 0;
      }
    }
    cnt += 1;
  }
  cout << lcm << "\n";
}
