#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007

bool dbgflag = false;

ll make_primes(ll max_value, vector<ll>&primes) {
  ll q = 2;
  ll cnt = 0;
  while (q <= max_value) {
    bool flag = true;
    for (ll p: primes) {
      if (q % p == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      primes.emplace_back(q);
      cnt++;
    }
    q++;
  }
  return cnt;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<map<int, int>> factorize(n);
  vector<ll> primes;
  ll pn = make_primes(n, primes);

  for (int i = 1; i <= n; i++) {
    int num = i;
    //if (dbgflag) cout << num << endl;
    for (int p: primes) {
      while (num % p == 0) {
        factorize[i-1][p]++;
        num /= p;
      }
    }
  }

  map<int, int> nf;
  for (int i = 0; i < n; i++) {
    for (int p: primes) {
      nf[p] += factorize[i][p];
    }
  }

  //if (dbgflag) cout << (nf[2]+1) * (nf[3]+1) * (nf[5]+1) * (nf[7]+1) << endl;
  int cnt = 0;
  vector<int> fcts = {1};
  
  for (int p: primes) {
    int s = fcts.size();
    for (int i = 0; i < s; i++) {
      for (int j = 1; j <= nf[p]; j++) {
        int k = (fcts[i])*(j+1);
        //cout << j << " " << k << endl;
        if (!((k == 1) || (k == 3) || (k == 5) || (k == 15) || (k == 25) || (k == 75))) continue;
        fcts.emplace_back((fcts[i])*(j+1));
      }
    }
  }

  for (int f: fcts) {
    if (dbgflag) cout << f << endl;
    if (f == 75) cnt++;
  }

  cout << cnt << endl;
}
