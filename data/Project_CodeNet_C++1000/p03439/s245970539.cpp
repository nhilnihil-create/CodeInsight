#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int l = 0, r = n;
    string zs;
    cout << 0 << endl;
    cin >> zs;
    if (zs == "Vacant") return 0;
    rep(i, 20) {
        int m = (l + r) / 2;
        string s;
        cout << m << endl;
        cin >> s;
        if (s == "Vacant") return 0;
        if ((m % 2) == 0) {
            if (zs != s) r = m;
            else l = m;
        }
        else {
            if (zs != s) l = m;
            else r = m;
        }
    }
    return 0;
}
