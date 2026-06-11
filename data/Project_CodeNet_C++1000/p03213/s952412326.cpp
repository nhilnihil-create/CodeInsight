#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

const int N = 110;
vector<int> pw;
int n;

int findPow (vector<int>& u, int x) {
  int res = 0;
  for (int i = 0; i < sz(u); i++) {
    while (u[i] % x == 0) { res++; u[i] /= x; }
  }
  cerr << x << ", " << res << "\n";
  return res;
}

int solve() {
  vector<int> u(n);
  for (int i = 0; i < n; i++) u[i] = i + 1;

  for (int i = 2; i <= n; i++) {
    int k = findPow(u, i);
    if (k) pw.push_back(k);
  }

  int ans = 0;
  int a = 0, b = 0; 
  
  for (int i = 0; i < sz(pw); i++) {
    if (pw[i] >= 4) a++;
    else if (pw[i] >= 2) b++;
  }
  cerr << a << ", " << b << "\n";
  ans += b * a * (a - 1) / 2;
  ans += a * (a - 1) * (a - 2) / 2;

  a = 0; b = 0;
  for (int i = 0; i < sz(pw); i++) {
    if (pw[i] >= 24) a++;
    else if (pw[i] >= 2) b++;
  }
  cerr << a << ", " << b << "\n";
  ans += a * b + a * (a - 1);

  a = 0; b = 0;
  for (int i = 0; i < sz(pw); i++) {
    if (pw[i] >= 14) a++;
    else if (pw[i] >= 4) b++;
  }
  cerr << a << ", " << b << "\n";
  ans += a * b + a * (a - 1);

  a = 0;
  for (int i = 0; i < sz(pw); i++) a += (pw[i] >= 74);
  cerr << a << ", " << b << "\n";
  ans += a;

  return ans;
}

int main() {
  scanf("%d", &n);
  printf("%d\n", solve());
}

