#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
typedef struct{
    ll x; ll y; ll z;
}Cake;
int main() {
    int n, m; cin >> n >> m;
    vector<Cake> cake(n);
    rep(i, n) cin >> cake[i].x >> cake[i].y >> cake[i].z;
    ll ans = 0;
    rep(i, 2)rep(j, 2)rep(k, 2) {
        vector<ll> score(n);
        rep(l, n) {
            score[l] += i ? cake[l].x : -cake[l].x;
            score[l] += j ? cake[l].y : -cake[l].y;
            score[l] += k ? cake[l].z : -cake[l].z;
        }
        sort(score.rbegin(), score.rend());
        ll t = 0;
        rep(l, m) t += score[l];
        ans = max(t, ans);
    }
    cout << ans;
}
