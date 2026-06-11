#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

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

int H, W, D;
int A[305][305];
ll X[305*305], Y[305*305];
ll Sum[305*305];

ll Dist(int i, int j){
  return abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
}

int main(){
  cin >> H >> W >> D;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> A[i][j];
      X[A[i][j]] = i; Y[A[i][j]] = j;
    }
  }

  for (int i = D + 1; i <= H * W; i++){
    Sum[i] = Sum[i - D] + Dist(i, i - D);
  }

  int Q; cin >> Q;
  for (int i = 0; i < Q; i++){
    int L, R; cin >> L >> R;
    cout << Sum[R] - Sum[L] << endl;
  }

  return 0;
}
