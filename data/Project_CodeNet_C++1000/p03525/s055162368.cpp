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

int N, D[55];
bool visited[24];

int Solve(int num){
  int ans = 24;
  for (int i = 0; i < 24; i++){
    if (!visited[i]) continue;
    ans = min(ans, min(abs(i-num), 24-abs(i-num)));
  }
  return ans;
}

int main(){
  visited[0] = true;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> D[i];
  sort(D, D + N);

  for (int i = 0; i < N; i++){
    if (D[i] == 0){
      cout << 0 << endl;
      return 0;
    }
    if (visited[D[i]] && visited[24-D[i]]){
      cout << 0 << endl;
      return 0;
    }
    if (!visited[D[i]] && !visited[24-D[i]]){
      if (Solve(D[i]) >= Solve(24-D[i])){
        visited[D[i]] = true;
      }else{
        visited[24-D[i]] = true;
      }
    }else{
      visited[D[i]] = true;
      visited[24-D[i]] = true;
    }
  }

  int ans = 24;
  for (int i = 0; i < 24; i++){
    if (!visited[i]) continue;
    for (int j = 0; j < 24; j++){
      if (i == j) continue;
      if (!visited[j]) continue;
      ans = min(ans, min(abs(i-j), 24-abs(i-j)));
    }
  }
  cout << ans << endl;

  return 0;
}
