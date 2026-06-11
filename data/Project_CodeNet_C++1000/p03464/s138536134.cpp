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
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll l = 2, r = 2;
    rrep(i, n) {
        if (((l - 1) / a[i]) == (r / a[i])) {
            cout << -1 << endl;
            return 0;
        }
        ll lset = ((i == (n - 1)) ? 1 : ((l + (a[i] - 1)) / a[i]));
        ll rset = ((i == (n - 1)) ? 1 : (r / a[i]));
        l = lset * a[i];
        r = (rset + 1) * a[i] - 1;
        // printf("l=%d, r=%d\n", l, r);
    }
    cout << l << " " << r << endl;
    return 0;
}
