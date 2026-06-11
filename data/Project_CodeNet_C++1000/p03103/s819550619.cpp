#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF (1<<18)


int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(n);
    rep(i,n) cin>>a[i]>>b[i];

    vector<pair<int, int>> ab(n);
    rep(i,n) ab[i] = make_pair(a[i], b[i]);

    sort(ab.begin(), ab.end());

    ll ans = 0;
    rep(i,n){
        int buy = min(m, ab[i].second);
        m -= buy;
        ans += (ll)buy*ab[i].first;
    }

    cout<<ans<<endl;

    return 0;
}