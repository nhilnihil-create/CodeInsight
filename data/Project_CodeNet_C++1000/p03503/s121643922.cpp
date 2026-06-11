#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 105;
ll n, ans, open[N][10], p[N][15];
ll solve(ll x){
    ll a[N] = {};
    for(int i = 0; i < 10; i++){
        if(x & (1 << i)){
            for(int j = 0; j < n; j++){
                if(open[j][i]) a[j]++;
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < n; i++){
        res += p[i][a[i]];
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++)
            cin >> open[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 11; j++)
            cin >> p[i][j];
    }
    ans = -1e18;
    for(int i = 1; i < (1 << 10); i++){
        ans = max(ans, solve(i));
    }
    cout << ans;
    return 0;
}
