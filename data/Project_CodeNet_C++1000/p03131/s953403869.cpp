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

ll K, A, B;
int main(){
  cin >> K >> A >> B;
  if (A + 2 >= B || K < A + 1){
    cout << K + 1 << endl;
    return 0;
  }

  ll ans = B; K -= A + 1;
  ans += (B - A) * (K / 2);
  if (K % 2 != 0) ans++;
  cout << ans << endl;

  return 0;
}
