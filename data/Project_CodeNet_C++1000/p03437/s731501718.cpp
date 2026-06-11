#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

    ll x, y;
    cin >> x >> y;

    if(x % y == 0){
        cout << -1 << endl;
        return 0;
    }

    for(ll i=1; x <= 1e18; ++i){
        ll z = x * i;
        if(z % y != 0){
            cout << z << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}