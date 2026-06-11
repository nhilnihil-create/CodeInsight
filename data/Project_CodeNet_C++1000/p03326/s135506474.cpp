#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
ll dp[3][1002][1002];
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x[3];
    rep(i,n){
        ll a[3];
        rep(cur,3){
            cin >> a[cur];
            x[cur].push_back(a[cur]);
        }
    }
    ll ans = 0;
    rep(i,8){
        vector<ll> v;
        rep(j,n){
        ll tmp = 0;
            if((i+1)&1){
                tmp += x[0][j];
            }else{
                tmp -= x[0][j];
            }
            if((i+1)&2){
                tmp += x[1][j];
            }else{
                tmp -= x[1][j];
            }
            if((i+1)&4){
                tmp += x[2][j];
            }else{
                tmp -= x[2][j];
            }
            v.push_back(tmp);
        }
        sort(v.rbegin(), v.rend());
        ll tmp = 0;
        rep(i,m){
            tmp += v[i];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
