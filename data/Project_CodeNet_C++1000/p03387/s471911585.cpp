#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c; cin >> a >> b >> c;
    int x[3] = {a, b, c};
    sort(x, x + 3);
    int d1 = x[2] - x[1];
    int d2 = x[2] - x[0];
    int ans;
    if ((d1 & 1) != (d2 & 1)) {
        d2++;
        ans = 1;
        if (d2 & 1) ans += 1 + d2 / 2 + d1 / 2;
        else ans += d2 / 2 + d1 / 2;
    } else {
        if (d1 & 1) ans = 1 + d1 / 2 + d2 / 2;
        else ans = d1 / 2 + d2 / 2;
    }
    cout << ans << nl;
}