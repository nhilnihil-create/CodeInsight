#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll n;
    cin >> n;
    vector<string> ss(n, "");
    ll ans = 0;
    ll a = 0;
    ll b = 0;
    ll ba = 0;
    rep(i, n) {
        cin >> ss[i];
        size_t it = 0;
        if (ss[i].front() == 'B' && ss[i].back() != 'A') b++;
        if (ss[i].front() != 'B' && ss[i].back() == 'A') a++;
        if (ss[i].front() == 'B' && ss[i].back() == 'A') ba++;

        while (it != string::npos) {
            it = ss[i].find("AB", it);
            if (it != string::npos) {
                it++;
                ans++;
            }
        }
    }
    ans += min(a, b);                       //XB AX
    ans += min(ba, max(a, b) - min(a, b));  // BA BX or XA BA
    ba -= min(ba, max(a, b) - min(a, b));   // not use BA
    ans += (!max(a, b) && ba > 0) ? ba - 1 : ba;
    cout << ans << endl;
}