#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#include<iomanip>
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1; i<=n;i++)
#define rrep(i,n) for(int i = n-1;i >=0;i--)
#define ALL(a) a.begin(),a.end()
#define PI  acos(-1)
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
typedef long long int ll;
typedef long double ld;
const int MOD = 1e9 + 7;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }, sum = 0,h,w;
ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return res;
}
int main() {
    int h, w; cin >> h >> w; ll ans = 0;
    vector<vector<int>> A(h, vector<int>(w));
    int dp[10][10];
    rep(i, 10) rep(j, 10) cin >> dp[i][j];
    rep(i, 10) rep(j, 10) rep(k, 10) dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
    rep(i, h) {
        rep(j, w) {
            cin >> A[i][j];
            if (A[i][j] == -1 || A[i][j] == 1) continue;
            ans += dp[A[i][j]][1];
        }
    }cout << ans << endl;
}