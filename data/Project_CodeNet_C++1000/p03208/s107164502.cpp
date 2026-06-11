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

int N, K, H[int(1e5+5)];

int main(){
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> H[i];
  sort(H, H + N);

  int ans = 1e9;
  for (int i = 0; i + K - 1 < N; i++){
    ans = min(ans, H[i + K - 1] - H[i]);
  }
  cout << ans << endl;

  return 0;
}
