#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int(i)=0;(i)<(n);(i)++)

long long gcd (long long a, long long b) {
  if(a%b==0) return b;
  else return gcd(b, a%b);
}

int main() {
  long long n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  long long GCD = gcd(n, m);
  long long lim = min(n, m);
  bool yes = true;
  int alpha = n / GCD;
  int beta = m / GCD;
  for(int k=0;(alpha*k<n && beta*k<m);k++) {
    if(s[alpha*k] != t[beta*k]) {
      yes = false;
      break;
    }
  }

  if(yes) cout << n * m / GCD << endl;
  else cout << -1 << endl;
}