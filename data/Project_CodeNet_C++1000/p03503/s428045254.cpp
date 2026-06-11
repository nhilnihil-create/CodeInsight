#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<bool>> f(n,vector<bool>(10,false));
    rep(i,n) rep(j,10) {
        int ftmp;
        cin >> ftmp;
        if(ftmp == 1) f[i][j] = true;
    }
    vector<vector<int>> p(n,vector<int>(11));
    rep(i,n) rep(j,11) cin >> p[i][j];
    const int INF = INT_MAX;
    int ans = -INF;
    for(int bits = 1;bits < 1<<10; bits++) {
        int anstmp = 0;
        vector<bool> op(10,false);
        rep(i,10) if(bits>>i&1) op[i] = true;
        rep(i,n) {
            int c = 0;
            rep(j,10) {
                if(f[i][j]&&op[j]) c++;
            }
            anstmp += p[i][c];
        }
        chmax(ans, anstmp);
    }
    cout << ans << endl;
}
