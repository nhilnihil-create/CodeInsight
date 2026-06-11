#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    string s; cin >> s;
    ll ss = s.size();

    int a_count = 0;
    // int bc_count = 0;
    ll ans = 0;
    ll cnt = 0;
    
    int i = 0;
    while (i < ss-1) {
        if (s[i] == 'A') {
            a_count += 1;
            i += 1;
        } else if (s[i] == 'B' && s[i+1] == 'C') {
            ans += a_count;
            i += 2;
            // bc_count = 0;
        } else {
            a_count = 0;
            i += 1;
        }
    }
    cout << ans << endl;
    return 0;
}