#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1;i <= (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
ll mod = 1000000007;

vector<ll> dp(100010,INF);

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    dp[0] = 0;
    rep(i,n) {
        rep1(j,k) {
            chmin(dp[i+j],dp[i] + abs(h[i+j] - h[i]));
        }
    }
    cout << dp[n-1] << endl;
}
