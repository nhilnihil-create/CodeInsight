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

int H, W, C[10][10];

int main(){
  cin >> H >> W;
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      cin >> C[i][j];
    }
  }
  for (int k = 0; k < 10; k++){
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < H * W; i++){
    int A; cin >> A;
    if (A < 0) continue;
    ans += C[A][1];
  }
  cout << ans << endl;


  return 0;
}
