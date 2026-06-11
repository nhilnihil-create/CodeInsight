#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(10));
    rep(i, n)rep(j, 10) cin >> f[i][j];
    vector<vector<int>> p(n, vector<int>(11));
    rep(i, n)rep(j, 11) cin >> p[i][j];

    ll ans = -20000000000;
    for(int i = 1; i < (1 << 10); ++i){
        vector<int> c(n, 0);
        rep(j, n){
            rep(k, 10){
                if((i & (1 << k)) && f[j][k]){
                    c[j]++;
                }
            }
        }
        ll sum = 0;
        rep(j, n){
            sum += p[j][c[j]];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}