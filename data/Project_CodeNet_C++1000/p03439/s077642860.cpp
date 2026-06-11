#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 998244353;
signed main() {
    int n;
    cin>>n;
    int l = 0, r = n - 1, m;
    string ls, rs, ms;
    cout<<l<<endl<<flush;
    cin>>ls;
    if (ls == "Vacant") return 0;
    cout<<r<<endl<<flush;
    cin>>rs;
    if (rs == "Vacant") return 0;

    while (r - l > 1) {
        m = (l + r) / 2;
        cout<<m<<endl<<flush;
        cin>>ms;
        if (ms == "Vacant") return 0;

        if ((m - l) % 2 == 0 && ms != ls) r = m, rs = ms;
        else if ((m - l) % 2 == 1 && ms == ls) r = m, rs = ms;
        else if ((r - m) % 2 == 0 && ms != rs) l = m, ls = ms;
        else if ((r - m) % 2 == 1 && ms == rs) l = m, ls = ms;
    }
    cout<<l<<endl<<flush;
    cin>>ls;
}