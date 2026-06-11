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

int D, G, ans = 1e9;
int P[10], C[10];

bool now[10];

int Judge(int num){
  for (int i = 0; i < D; i++){
    now[i] = num % 2;
    num /= 2;
  }
  return 0;
}

int Solve(int num){
  Judge(num);
  int cnt = 0, sum = 0;
  for (int i = 0; i < D; i++){
    if (!now[i]) continue;
    cnt += P[i];
    sum += P[i] * (i+1) * 100 + C[i];
  }

  int rest = G - sum;
  if (rest <= 0){
    ans = min(ans, cnt);
    return 0;
  }

  for (int i = 0; i < D; i++){
    if (now[i]) continue;

    int res = rest / ((i+1)*100);
    if (rest % ((i+1)*100) > 0) res++; 

    if (res > P[i]) continue;
    ans = min(ans, cnt + res);
  }

  return 0;
}

int main(){
  cin >> D >> G;
  for (int i = 0; i < D; i++){
    cin >> P[i] >> C[i];
  }
  for (int i = 0; i < (1<<D); i++){
    Solve(i);
  }
  cout << ans << endl;

  return 0;
}
