#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  int N; cin >> N;
  vector<int> a(N); REP(i, N) cin >> a[i];
  sort(ALL(a));
  int n = a[N-1], r = a[0], rr = n;
  REP(i, N-1) {
    if (rr >= abs(n/2-a[i])) {
      r = a[i];
      rr = abs(n/2-a[i]);
    }
  }
  printf("%d %d\n", n, r);
}