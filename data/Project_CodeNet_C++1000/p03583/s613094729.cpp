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

int main(){
  ll N; cin >> N;

  for (ll h = 1; h <= 3500; h++){
    for (ll n = 1; n <= 3500; n++){
      ll A = 4*h*n-N*n-N*h;
      if (A == 0) continue;
      ll B = N*h*n;
      if (B % A != 0) continue;
      
      ll w = B / A;
      if (w <= 0) continue;
      cout << h << " " << n << " " << w << endl;
      return 0;
    }
  }

  return 0;
}
