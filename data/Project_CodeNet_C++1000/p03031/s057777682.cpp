


#include <bits/stdc++.h>

#define loop(s, e, i) for (int i=s; i<e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;


int P[100];

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> S(N);

  loop(0, M, i) {
    ll k;
    cin >> k;
    loop(0, k, j) {
      ll s;
      cin >> s;
      s--;
      S[s].emplace_back(i);
    }
  }
  loop(0, M, i) {
    cin >> P[i];
  }

  ll count = 0;
  for (int bit=0; bit<(1 << N); bit++) {
    vector<ll> KON(M, 0);
    loop(0, N, i) {
      if (bit & (1<<i)) {
        for (auto si : S[i]) {
          KON[si]++;
        }
      }
    }
    bool allon = true;
    loop(0, M, i) {
      if (KON[i] % 2 != P[i]) {
        allon = false;
        break;
      }
    }
    if (allon) {
      count++;
    }
  }
  print(count);
}