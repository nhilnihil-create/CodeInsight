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

int N, C;
ll D[35][35], c[505][505];
ll ans[3][35], res = 1e18;

int main(){
  cin >> N >> C;
  for (int i = 1; i <= C; i++){
    for (int j = 1; j <= C; j++){
      cin >> D[i][j];
    }
  }
  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++){
      cin >> c[i][j];
      for (int k = 1; k <= C; k++){
        ans[(i+j)%3][k] += D[c[i][j]][k];
      }
    }
  }

  for (int i = 1; i <= C; i++){
    for (int j = 1; j <= C; j++){
      for (int k = 1; k <= C; k++){
        if (i == j || j == k || k == i) continue;
        res = min(res, ans[0][i] + ans[1][j] + ans[2][k]);
      }
    }
  }
  cout << res << endl;

  return 0;
}
