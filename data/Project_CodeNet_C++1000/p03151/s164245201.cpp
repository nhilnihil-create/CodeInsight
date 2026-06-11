#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    int n; cin >> n;
    V<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    ll o = 0, s = 0;
    V<ll> v;
    for(int i = 0; i < n; i++){
        if(a[i] <= b[i]) s += b[i] - a[i];
        else{
            o += a[i] - b[i];
            v.push_back(a[i] - b[i]);
        }
    }

    if(o < s){
        cout << -1 << endl;
        return 0;
    }
    if(s == 0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = n;
    ll x = o - s;
    if(0 < x){
        int m = v.size();
        sort(ALL(v));
        for(int i = 0; i < m; i++){
            if(0 <= x - v[i]){
                ans--;
                x -= v[i];
            }
        }
    }
    cout << ans << endl;

    return 0;
}
