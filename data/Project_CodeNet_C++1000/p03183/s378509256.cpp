#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> i3;
ll n, w[1005], s[1005], v[1005];
ll dp[1005][10005];

ll solve(ll pos, ll left){
    if(left < 0) return -1e9;
    if(pos == n) return 0;
    if(dp[pos][left] != -1) return dp[pos][left];
    ll r1 = solve(pos+1, left);
    ll r2 = solve(pos+1, min(left-w[pos], s[pos]) ) + v[pos];
    return dp[pos][left] = max(r1,r2);
}

bool func(i3 a, i3 b){
    return (get<1>(a)+get<0>(a)) > (get<1>(b)+get<0>(b));
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> n;
    vector<i3> vec;
    for(ll i = 0; i < n; i++){
        ll a, b, c; cin >> a >> b >> c;
        vec.emplace_back(a, b, c);
    }
    sort(vec.begin(), vec.end(), func);
    for(ll i = 0; i < n; i++)
        tie(w[i], s[i], v[i]) = vec[i];
    ll res = 0;
    for(ll i = 0; i < n; i++)
        res = max(res, solve(i+1, s[i]) + v[i]);
    cout << res << endl;
    return 0;
}