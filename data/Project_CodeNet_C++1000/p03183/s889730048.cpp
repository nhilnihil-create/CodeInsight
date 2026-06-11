#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << ENDL
#define all(a) begin(a),end(a)
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

bool cmp(pair<ii, lli> u, pair<ii, lli> v) {
    return (u.f.f + u.f.s) < (v.f.f + v.f.s);
}

const int MAX = 2e4 + 5;

int main()
{   _
    lli n; cin >> n;
    vector<pair<ii, lli>> t(n);
    fore(i, 0, n) cin >> t[i].f.f >> t[i].f.s >> t[i].s;
    vector<lli> dp(MAX, 0);
    sort(all(t), cmp);
    fore(i, 0, n) {
        ///cout << "---" << t[i].f.f << ' ' << t[i].f.s << ' ' << t[i].s << ENDL;
        for(int j = t[i].f.s; j >= 0; --j) {
            if(j + t[i].f.f < MAX) {
                dp[j + t[i].f.f] = max(dp[j + t[i].f.f], dp[j] + t[i].s);
           ///     cout << j + t[i].f.f << ' ' << t[i].s << ' ' << dp[j + t[i].f.f] << ENDL;
            }
        }
    }
    lli ans = 0;
    for(auto it : dp) ans = max(ans, it);
    cout << ans << ENDL;
    return 0;
}
