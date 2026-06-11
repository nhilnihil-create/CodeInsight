#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll Bit[40];

ll Solve(ll num){
  ll ans = 0;
  for (int i = 0; i < 40; i++){
    ll now = (num / Bit[i]) * (Bit[i] / 2);
    now += max(num % Bit[i] - (Bit[i]/2 - 1), 0ll);
    if (now % 2 != 0) ans += Bit[i] / 2;
  }
  return ans;
}


int main(){
  Bit[0] = 2;
  for (int i = 1; i < 40; i++) Bit[i] = Bit[i-1] * 2;

  ll A, B; cin >> A >> B;
  ll ans = Solve(A - 1) ^ Solve(B);
  cout << ans << endl;

  return 0;
}
