#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;

ll r(ll x, ll y) {
  if (y == 0) return 1;
  else if (y % 2 == 0) return r(x, y/2) * r(x, y/2) % mod;
  else return x * r(x, (y-1)/2) % mod * r(x, (y-1)/2) % mod;
}


int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> p(1, 0);
  if (s[0] == '1') p[0]++;
  else p[0]--;
  int c = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == '0') {
      if (p[c] < 0) p[c]--;
      else {
        c++;
        p.push_back(-1);
      }
    }
    else {
      if (p[c] > 0) p[c]++;
      else {
        c++;
        p.push_back(1);
      }
    }
  }
  
  int N = p.size();
  ll sum = 0;
  int K;
  if (p[0] > 0) {
    K = 2 * k + 1;
    for (int i = 0; i < min(K, N); i++) {
      sum += max(p[i], 0 - p[i]);
    }
  }
  else {
    K = 2 * k;
    for (int i = 0; i < min(K, N); i++) {
      sum += max(p[i], 0 - p[i]);
    }
  }
  
  if (K >= N) cout << sum <<endl;
  else {
    ll M = sum;
    int end = K - 1;
    int ini = 0;
    p.push_back(0);
    p.push_back(0);
    while (end < N) {
      if (p[ini] > 0) {
        sum -= p[ini];
        ini++;
      }
      else {
        sum += p[ini];
        ini++;
        end++;
        sum -= p[end];
        end++;
        sum += p[end];
        M = max(M, sum);
      }
    }
    cout << M <<endl;
  }   
}