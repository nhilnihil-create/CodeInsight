#include<bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define print(x) cout << (x) << endl;
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
using namespace std;
using ll = long long;

int main(void) {
    string s;
    cin >> s;

    ll ans = 0;
    int cnta = 0, cntbc = 0;
    rep (i, s.size() - 1) {
        if (s[i] == 'A') {
            cnta ++;
        }   
        else if (s[i] == 'B' && s[i + 1] == 'C') {
            ans += cnta;
            i++;
        }
        else cnta = 0;
    }
    
    cout << ans << endl;
    return 0;
}