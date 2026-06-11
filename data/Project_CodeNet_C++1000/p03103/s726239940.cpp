#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

int main() {

    ll n,m; cin >> n >> m;
    ll ans = 0;
    pair<ll,ll> p[100001];
    rep(i,n) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p,p+n);

    rep(i,n){
        while(p[i].second != 0 && m != 0){
            ans += p[i].first;
            p[i].second --;
            m --;
        }
    }

    cout << ans;

    return 0;
}









