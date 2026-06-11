#define print(x) printf("%d\n",x)

#include <queue>
typedef long long ll;

#include <iostream>
#define REP(i,n) for(int i=0; i<(int)(n); i++)

#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>

using namespace std;

ll calc(const vector<ll> &s, ll x, int b){
  const int n = s.size();
  ll ans = x * n + x * b;
  REP(i,n){
    const int k = i / b;
    const int m = k == 0 ? 5 : (5 + (k - 1) * 2);
    ans += m * s[i];
  }
  return ans;
}


int main(){
  const int n = getInt();
  const ll x = getInt();
  vector<ll> s(n);
  REP(i,n) s[n - 1 - i] = getInt();

  int mx = n;
  int mn = 1;
  REP(i,50){
    const int d = mx - mn;
    const int m1 = mn + d / 3;
    const int m2 = mn + 2 * d / 3;

    const ll a1 = calc(s, x, m1);
    const ll a2 = calc(s, x, m2);
    // printf("%d=%lld %d=%lld : %d %d\n", m1, a1, m2, a2, mn, mx);
    if(a1 < a2) mx = m2;
    else mn = m1;
  }

  ll ans = 1ll << 60;
  for(int i = mn; i <= mx; i++){
    ans = min(ans, calc(s, x, i));
    // printf("%d => %lld\n", i, calc(s, x, i));
  }
  printf("%lld\n", ans);

  return 0;
}