#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int MAX = 1e5+5;
int A, B, Q; ll s[MAX], t[MAX], x;
int main() {
  scanf("%d %d %d", &A, &B, &Q);
  for(int i = 1; i <= A; ++i) scanf("%ld", &s[i]);
  for(int i = 1; i <= B; ++i) scanf("%ld", &t[i]);
  s[0] = t[0] = -INF, s[A+1] = t[B+1] = INF;
  for(int i = 1; i <= Q; ++i) {
    scanf("%ld", &x);
    auto sitr = lower_bound(s+1, s+A+1, x);
    ll sv[2] = {*(sitr-1), *sitr};
    auto titr = lower_bound(t+1, t+B+1, x);
    ll tv[2] = {*(titr-1), *titr};
    ll ans = INF;
    for(int j = 0; j < 2; ++j) {
      for(int k = 0; k < 2; ++k) {
        ans = min(ans, abs(sv[j]-x)+abs(sv[j]-tv[k]));
        ans = min(ans, abs(tv[k]-x)+abs(tv[k]-sv[j]));
      }
    }
    printf("%ld\n", ans);
  }
}