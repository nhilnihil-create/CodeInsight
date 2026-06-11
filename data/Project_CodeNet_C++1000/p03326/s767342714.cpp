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

int N, M;
ll X[1005], Y[1005], Z[1005];

ll ans = -1e18, sum[1005];
int Solve(bool x, bool y, bool z){
  fill(sum, sum + N, 0);
  for (int i = 0; i < N; i++){
    sum[i] = X[i] * pow(-1, x) + Y[i] * pow(-1, y) + Z[i] * pow(-1, z);
  }
  sort(sum, sum + N, greater<ll>());

  ll res = 0;
  for (int i = 0; i < M; i++) res += sum[i];
  ans = max(ans, res);
  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    cin >> X[i] >> Y[i] >> Z[i];
  }

  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < 2; k++){
        Solve(i, j, k);
      }
    }
  }
  cout << ans << endl;


  return 0;
}

