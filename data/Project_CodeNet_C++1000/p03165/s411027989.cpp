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

int DP[3005][3005];
string S, T;
char ans[3005];

int main(){
  cin >> S >> T;
  int N = S.length(), M = T.length();
  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= M; j++){
      if (S[i-1] == T[j-1]){
        DP[i][j] = DP[i-1][j-1] + 1;
      }else{
        DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
      }
    }
  }

  int I = N, J = M;
  while (DP[I][J] > 0){
    while (DP[I][J] == DP[I-1][J]) I--;
    while (DP[I][J] == DP[I][J-1]) J--;
    ans[DP[I][J]] = S[I-1];
    I--; J--;
  }

  for (int i = 1; i <= DP[N][M]; i++) cout << ans[i];
  cout << endl;

  return 0;
}
