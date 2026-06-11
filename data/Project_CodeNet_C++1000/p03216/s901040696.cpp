#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

ll n, q;
string s;

void solve() {
    ll k;
    cin >> k;
    ll d = 0, m = 0, dm = 0, ans = 0;
    rep(i, n) {
        if (i >= k) {
            if (s[i - k] == 'D') {
                dm -= m;
                d--;
            }
            else if (s[i - k] == 'M') {
                m--;
            }
        }
        if (s[i] == 'D') {
            d++;
        }
        else if (s[i] == 'M') {
            m++;
            dm += d;
        }
        else if (s[i] == 'C') {
            ans += dm;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    cin >> n >> s >> q;
    rep(i, q) solve();
    return 0;
}
