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

int N, K;
ll X[55], Y[55], ans = INF;

int Solve(int A, int B, int C, int D){
  ll x[4] = {X[A], X[B], X[C], X[D]};
  ll y[4] = {Y[A], Y[B], Y[C], Y[D]};
  sort(x, x + 4); sort(y, y + 4);

  if (x[0] == x[3] || y[0] == y[3]) return 0;

  int cnt = 0;
  for (int i = 0; i < N; i++){
    if (x[0] <= X[i] && X[i] <= x[3] && y[0] <= Y[i] && Y[i] <= y[3]) cnt++;
  }

  if (cnt >= K){
    ans = min(ans, (x[3] - x[0]) * (y[3] - y[0]));
  }
  return 0;
}

int main(){
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  for (int i = 0; i < N; i++){
    for (int j = i; j < N; j++){
      for (int k = j; k < N; k++){
        for (int l = k; l < N; l++){
          Solve(i, j, k, l);
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
