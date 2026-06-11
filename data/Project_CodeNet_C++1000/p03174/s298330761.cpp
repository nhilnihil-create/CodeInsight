#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, r, n) for (int i = (r); i <= (n); i++)

using ll = long long;
using namespace std;

const ll MOD = 1000000007;

int main(){
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n)); rep(i,n) rep(j,n) cin >> a[i][j];
    vector<ll> ans(1<<n,0); ans[0] = 1;
    rep(i,(1<<n)-1){
        int num = __builtin_popcount(i);
        rep(j,n) if(!(i & 1<<j) && a[num][j]) ans[i^(1<<j)] += ans[i], ans[i^(1<<j)] %= MOD;
    }
    cout << ans[(1<<n)-1] << endl;
}