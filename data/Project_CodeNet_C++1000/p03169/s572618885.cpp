#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<double, double>P;
typedef tuple<ll, int, int>T;
#define PI 3.14159265358979


int main(){
  int N, A[303], C[4];
double dp[303][303][303];
  cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) C[A[i]]++;
 
    rep(c3, N + 1) rep(c2, N + 1) rep(c1, N + 1) {
        int sm = c1 + c2 + c3;
        if (sm == 0) continue;
 
        dp[c1][c2][c3] = 1.0 * N / sm;
        if (c1) dp[c1][c2][c3] += dp[c1 - 1][c2][c3] * c1 / sm;
        if (c2) dp[c1][c2][c3] += dp[c1 + 1][c2 - 1][c3] * c2 / sm;
        if (c3) dp[c1][c2][c3] += dp[c1][c2 + 1][c3 - 1] * c3 / sm;
    }
 
    printf("%.10f\n", dp[C[1]][C[2]][C[3]]);
}
