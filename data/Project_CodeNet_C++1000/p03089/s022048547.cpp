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

int N, B[105];
bool used[105];
int ans[105], cnt[105];

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> B[i];
  }

  for (int i = 0; i < N; i++){
    cnt[0] = used[0];
    for (int j = 1; j < N; j++){
      cnt[j] = cnt[j - 1];
      if (used[j]) cnt[j]++;
    }

    for (int j = N - 1; j >= 0; j--){
      if (used[j]) continue;
      if (cnt[j] + 1 == B[j]){
        ans[i] = B[j];
        used[j] = true;
        break;
      }
    }

    if (ans[i] == 0){
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = 0; i < N; i++){
    cout << ans[i] << endl;
  }

  return 0;
}
