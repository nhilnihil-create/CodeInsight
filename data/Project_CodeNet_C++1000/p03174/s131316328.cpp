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

int N, A[25][25];
ll DP[int(3e6+5)];

int Bit(int num){
  int ans = 0;
  while (num > 0){
    if (num % 2 != 0) ans++;
    num /= 2;
  }
  return ans;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> A[i][j];
    }
  }
  
  DP[0] = 1;
  for (int i = 0; i < (1<<N); i++){
    int num = Bit(i);

    for (int j = 0; j < N; j++){
      int now = 1 << j;
      int Judge = now & i;
      if (Judge > 0) continue;
      if (A[num][j] == 0) continue;

      DP[now + i] += DP[i];
      DP[now + i] %= MOD;
    }
  }

  cout << DP[(1<<N) - 1] << endl;

  return 0;
}
