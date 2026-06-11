// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)


int dp[1001][1001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(3)); rep(i,n) rep(j,3) cin >> a[i][j];
    ll ans = 0LL;
    for(int bit = 0; bit < 8; ++bit){
        sort(a.begin(), a.end(), [&](vector<ll> a, vector<ll> b){
            ll a1 = 0LL, b1 = 0LL;
            rep(i,3){
                if(bit & (1 << i)){
                    a1 += a[i];
                    b1 += b[i];
                }else{
                    a1 -= a[i];
                    b1 -= b[i];
                }
            }
            return a1 < b1;
        });
        ll tmp[3]; rep(i,3) tmp[i] = 0LL;
        rep(i,m) rep(j,3){
            if(bit & (1 << j)) tmp[j] += a[i][j];
            else tmp[j] -= a[i][j];
        }
        ll ret = 0LL;
        rep(i,3) ret += abs(tmp[i]);
        ans = max(ans, ret);
    }
    cout << ans << endl;
}