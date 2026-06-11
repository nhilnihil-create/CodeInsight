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
    map<ll, ll> md;
    for(int i = 0; i < n; i++){
        ll d; cin >> d;
        md[d]++;
    }
    int m; cin >> m;
    V<ll> v(m);
    for(int i = 0; i < m; i++) cin >> v[i];

    bool ok = true;
    for(int i = 0; i < m; i++){
        if(0 < md[v[i]]) md[v[i]]--;
        else{
            ok = false;
            break;
        }
    }

    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}
