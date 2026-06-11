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

int N, M, K[15], S[15][15], P[15], ans, Solve(int);
int now[15];

int main(){
  cin >> N >> M;
  for (int i = 1; i <= M; i++){
    cin >> K[i];
    for (int j = 0; j < K[i]; j++){
      cin >> S[i][j];
    }
  }
  for (int i = 1; i <= M; i++) cin >> P[i];
  for (int i = 0; i < (1<<N); i++) Solve(i);
  cout << ans << endl;

  return 0;
}

int Solve(int num){
  for (int i = 1; i <= N; i++){
    now[i] = num % 2; num /= 2;
  }

  for (int i = 1; i <= M; i++){
    int cnt = 0;
    for (int j = 0; j < K[i]; j++){
      if (now[S[i][j]]) cnt++;
    }
    if (cnt % 2 != P[i]) return 0;
  }
  ans++;
  return 0;
}


