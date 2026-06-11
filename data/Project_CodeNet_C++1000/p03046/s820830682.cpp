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

int M, K, ans[int(2e5+5)];

int main(){
  cin >> M >> K;

  if (M == 0){
    if (K > 0) cout << -1 << endl;
    else cout << "0 0" << endl;
    return 0;
  }

  if (M == 1){
    if (K > 0) cout << -1 << endl;
    else cout << "0 0 1 1" << endl;
    return 0;
  }

  int all = 1;
  for (int i = 0; i < M; i++){
    all = all << 1;
  }

  if (K >= all){
    cout << -1 << endl;
    return 0;
  }

  if (K == 0){
    cout << 0;
    for (int i = 1; i < all; i++) cout << " " << i;
    for (int i = all-1; i >= 0; i--) cout << " " << i;
    cout << endl;
    return 0;
  }

  cout << 0 << " " << K << " " << 0;
  for (int i = 1; i < all; i++){
    if (i == K) continue;
    cout << " " << i;
  }
  cout << " " << K;
  for (int i = all - 1; i >= 1; i--){
    if (i == K) continue;
    cout << " " << i;
  }
  cout << endl;


  return 0;
}
