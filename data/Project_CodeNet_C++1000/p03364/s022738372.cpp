#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
typedef long long ll;
//const ll INF = 10000000000;
//const ll MOD = 1000000007;

int main() {
    //cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    char S[N][N];
    rep(i, N) rep(j, N) cin >> S[i][j];
    bool is_same[N][N];
    rep(i, N) rep(j, N) is_same[i][j] = true;
    
    rep(i, N) rep(j, N) rep(k, N) {
        if (S[(i+k)%N][j]!=S[i][(j+k)%N]) is_same[i][j] = false;
    }
    
    int ans = 0;
    
    rep(i, N) rep(j, N) {
        bool flag = true;
        rep(k, N) flag &= is_same[(i+k)%N][(j+k)%N];
        if (flag) ans++;
    }
    
    cout << ans << endl;
}