#include <bits/stdc++.h>
#define pb push_back
#define mkp make_pair
#define llu unsigned long long int
#define ll long long
#define ld long double
#define foi(a, n) for (int i = a; i < n; i++)
#define foj(a, n) for (int j = a; j < n; j++)
#define foin(a, n) for (int i = n; i >= a; i--)
#define fojn(a, n) for (int j = n; j >= a; j--)
#define isp2(x) x && (!(x & (x - 1)))
#define ee 1000000007
#define fio                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL)
#define cases                                                                  \
  long long t;                                                                 \
  cin >> t;                                                                    \
  while (t--)

using namespace std;

int main() {
  ll t, x;
  cin >> t >> x;
  double ans = 1.0;
  ans = (1.0 * t / x);
  printf("%.10f\n", ans);
  return 0;
}
