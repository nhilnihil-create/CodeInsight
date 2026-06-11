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

int N; ll H;
Pll P[int(1e5+5)], Q[int(1e5+5)];

int main(){
  cin >> N >> H;
  for (int i = 0; i < N; i++){
    cin >> P[i].fi >> P[i].se;
    Q[i] = {P[i].se, P[i].fi};
  }
  sort(P, P + N, greater<Pll>());
  sort(Q, Q + N, greater<Pll>());

  ll ans = 0;
  for (int i = 0; i < N; i++){
    if (Q[i].fi < P[0].fi) break;
    ans++; H -= Q[i].fi;
    if (H <= 0){
      cout << ans << endl;
      return 0;
    }
  }
  ans += H / P[0].fi;
  if (H % P[0].fi != 0) ans++;
  cout << ans << endl;

  return 0;
}
