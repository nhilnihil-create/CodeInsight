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

int N;
ll A[405], sum[405], DP[405][405];
bool visited[405][405];

ll Solve(int L, int R){
  if (visited[L][R]) return DP[L][R];
  visited[L][R] = true;
  if (L == R) return 0;
  ll ans = 1e18;
  for (int i = L; i + 1 <= R; i++){
    ans = min(ans, Solve(L, i) + Solve(i + 1, R));
  }
  return DP[L][R] = ans + sum[R] - sum[L-1];
}

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    sum[i] = sum[i-1] + A[i];
  }
  cout << Solve(1, N) << endl;

  return 0;
}
