#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

ll solve(ll y, ll ans, ll now, const ll c[10][10]){
    //printf("y: %lld, ans: %lld, now: %lld\n", y, ans, now);
    if(y == 1) return now;
    rep(x, 10){
        if(x == y || now + c[y][x] > ans) continue;
        ans = min(ans, solve(x, ans, now+c[y][x], c));
        //cout << "================" << endl;
    }
    return ans;
}

int main(){
    ll h, w; cin >> h >> w;
    ll c[10][10];
    rep(i, 10) rep(j, 10) cin >> c[i][j];

    vector<ll> mp(10, -1);
    ll ans = 0;
    rep(i, h){
        rep(j, w){
            ll a; cin >> a;
            if(a == -1 || a == 1) continue;            
            if(mp[a] == -1) mp[a] = solve(a, c[a][1], 0, c);
            ans += mp[a];
        }
    }

    //for(auto i : mp) cout << i << " "; cout << endl;
    cout << ans << endl;
    return 0;
}