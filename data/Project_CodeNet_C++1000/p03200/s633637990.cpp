#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    string s; cin >> s;

    ll ans = 0, w = 0;
    bool ok = false;
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'B') ok = true;
        if(s[i] == 'W' && ok) {
            ans += i - w;
        }
        if(s[i] == 'W') w++;
    }
    cout << ans << endl;

    return 0;
}
