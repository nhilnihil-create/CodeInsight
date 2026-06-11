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

int X, Y, Z, K;
ll A[1005], B[1005], C[1005];
vector <ll> AB, ans;

int main(){
  cin >> X >> Y >> Z >> K;
  for (int i = 0; i < X; i++) cin >> A[i];
  for (int j = 0; j < Y; j++) cin >> B[j];
  for (int k = 0; k < Z; k++) cin >> C[k];

  for (int i = 0; i < X; i++){
    for (int j = 0; j < Y; j++){
      AB.push_back(A[i] + B[j]);
    }
  }
  sort(AB.begin(), AB.end(), greater<ll>());

  for (int i = 0; i < min(int(AB.size()), K); i++){
    for (int j = 0; j < Z; j++){
      ans.push_back(AB[i] + C[j]);
    }
  }
  sort(ans.begin(), ans.end(), greater<ll>());
  for (int i = 0; i < K; i++) cout << ans[i] << endl;

  return 0;
}
