#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> v;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        v.push_back(a + b);
        ans -= b;
    }
    sort(v.rbegin(), v.rend());

    rep(i, n){
        if(i % 2 == 0){
            ans += v[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}
