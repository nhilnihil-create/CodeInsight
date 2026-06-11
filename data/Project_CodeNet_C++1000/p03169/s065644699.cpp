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

int N, cnt[5];
double DP[305][305][305];

double Solve(int i, int j, int k){
  if (DP[i][j][k] != -1) return DP[i][j][k];
  if (i > N || j > N || k > N) return 0;

  double ans = 0;
  if (i > 0){
    ans += Solve(i-1, j, k) * (double)i / (double)(i+j+k);
  }
  if (j > 0){
    ans += Solve(i+1, j-1, k) * (double)j / (double)(i+j+k);
  }
  if (k > 0){
    ans += Solve(i, j+1, k-1) * (double)k / (double)(i+j+k); 
  }
  ans += (double)N / (double)(i+j+k);

  return DP[i][j][k] = ans;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    int A; cin >> A; cnt[A]++;
  }
  fill((double*)DP, (double*)(DP+N+1), -1);
  DP[0][0][0] = 0;

  printf("%.10lf\n", Solve(cnt[1], cnt[2], cnt[3]));

  return 0;
}
