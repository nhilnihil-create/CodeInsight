#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define ll long long
#define pii pair < int, int >
#define fr first
#define sc second
#define mk make_pair
#define sz(s) (int)s.size()
#define all(s) s.begin(), s.end()
#define ok cerr << "ok\n";
#define whatis(x) cerr << #x << " = " << x << endl;

const int N = (int)3e5 + 7;
const int inf = (int)1e9 + 7;

int ans[N];
int n, a, b;
bool used[N];

void printans() {
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  exit(0);
}

void no() {
  puts("-1");
  exit(0);
}

main() {
  scanf("%d %d %d", &n, &a, &b);
  if (a + b - 1 > n) {
    no();
  }
  int in = n;
  if (a + b - 1 == n) {
    for (int i = a; i >= 1; i--) {
      ans[i] = in--;
    }
    for (int i = a + 1; i <= n; i++) {
      ans[i] = in--;
    }
    printans();
  }
  for (int i = n - b + 1; i <= n; i++) {
    ans[i] = in--;
  }
  int ost = n - b;
  a--;
  if (a > ost || a <= 0) {
    no();
  }
  int st = 1;
  int sub;
  int ind = 1;
  for (int i = n - b + 1 - a; i >= 1; i -= a) {
    for (int j = i; j <= i + a - 1; j++) {
      if (ind > ost) no();
      ans[j] = ind++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i]) break;
    ans[i] = ind++;
  }
  a++;
  vector < int > d(n + 1, inf);
  d[0] = -inf;
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(d.begin(), d.end(), ans[i]) - d.begin();
    d[pos] = ans[i];
  }
  in = n;
  while (d[in] == inf) in--;
  if (in != a) no();
  for (int i = 0; i < d.size(); i++) {
    d[i] = inf;
  }
  d[0] = -inf;
  for (int i = n; i >= 1; i--) {
    int pos = lower_bound(d.begin(), d.end(), ans[i]) - d.begin();
    d[pos] = ans[i];
  }
  in = n;
  while (d[in] == inf) in--;
  if (in != b) no();
  for (int i = 1; i <= n; i++) {
    if (ans[i] <= 0 || ans[i] > n || used[ans[i]]) {
      no();
    }
    used[ans[i]] = 1;
  }
  printans();
}
