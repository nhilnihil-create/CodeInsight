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

int N, M;
ll all[3][1005];
ll sum[8][1005];

int Get(int i, int j){
  int num = j;

  for (int k = 0; k < 3; k++){
    if (num % 2 == 0) sum[j][i] += all[k][i];
    else sum[j][i] -= all[k][i];
    num /= 2;
  }

  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    ll X, Y, Z; cin >> X >> Y >> Z;
    all[0][i] = X; all[1][i] = Y; all[2][i] = Z;

    for (int j = 0; j < 8; j++) Get(i, j);
  }


  ll ans = 0;
  for (int k = 0; k < 8; k++){
    sort(sum[k], sum[k] + N, greater<ll>());
    ll now = 0;
    for (int j = 0; j < M; j++) now += sum[k][j];
    ans = max(ans, now);
  }
  cout << ans << endl;

  return 0;
}
