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
vector <Pii> ans;

int main(){
  int N; cin >> N;

  if (N % 2 == 0){
    for (int i = 1; i <= N; i++){
      for (int j = i + 1; j <= N; j++){
        if (i + j == N + 1) continue;
        ans.push_back({i, j});
      }
    }
  }else{
    for (int i = 1; i < N; i++){
      ans.push_back({i, N});
    }
    for (int i = 1; i < N; i++){
      for (int j = i + 1; j < N; j++){
        if (i + j == N) continue;
        ans.push_back({i, j});
      }
    }

  }


  int M = ans.size();
  cout << M << endl;
  for (int i = 0; i < M; i++){
    cout << ans[i].fi << " " << ans[i].se << endl;
  }

  return 0;
}
