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

ll Pow(ll A, ll N){
  if (N == 0) return 1;
  if (N % 2 == 0) return Pow(A * A % MOD, N / 2);
  return Pow(A * A % MOD, N / 2) * A % MOD;
}

int N; ll DP[int(1e5+5)][4];
string S;

int main(){
  cin >> S; N = S.length();

  int cnt = 0;
  DP[0][0] = 1;
  for (int i = 1; i <= N; i++){
    if (S[i-1] == 'A'){
      for (int j = 1; j < 4; j++) DP[i][j] += DP[i-1][j];
      DP[i][1] += DP[i-1][0];
    }else if (S[i-1] == 'B'){
      for (int j = 1; j < 4; j++) DP[i][j] += DP[i-1][j];
      DP[i][2] += DP[i-1][1];
    }else if (S[i-1] == 'C'){
      for (int j = 1; j < 4; j++) DP[i][j] += DP[i-1][j];
      DP[i][3] += DP[i-1][2];
    }else{
      for (int j = 1; j < 4; j++){
        DP[i][j] += DP[i-1][j] * 3 + DP[i-1][j-1];
      }
      cnt++;
    }
    DP[i][0] = Pow(3, cnt);
    for (int j = 0; j < 4; j++) DP[i][j] %= MOD;
  }
  cout << DP[N][3] << endl;


  return 0;
}
