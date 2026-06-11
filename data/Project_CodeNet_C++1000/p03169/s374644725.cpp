#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back

int N;
int a[310];
int cnt[4];
double memo[310][310][310];

double f(int i, int j, int k) {
    if (memo[i][j][k]!=-1) return memo[i][j][k];
    if (i==0 && j==0 && k==0) return memo[i][j][k] = 0;
    double res = N;
    if (i>0) res += i*f(i-1, j, k);
    if (j>0) res += j*f(i+1, j-1, k);
    if (k>0) res += k*f(i, j+1, k-1);
    res /= i+j+k;
    return memo[i][j][k] = res;
}
 
int main() {
    cin >> N;
    rep(i, N) cin >> a[i];
    rep(i, N) cnt[a[i]]++;
    rep(i, 310) rep(j, 310) rep(k, 310) memo[i][j][k] = -1;
    cout << fixed << setprecision(12) << f(cnt[1], cnt[2], cnt[3]) << endl;
}