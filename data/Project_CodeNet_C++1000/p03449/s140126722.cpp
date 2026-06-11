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
    int n; cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    F0R(i, n) {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
    F0R(i, n) {
        cin >> b[i + 1];
        b[i + 1] += b[i];
    }
    int ans = 0;
    FOR(i, 1, n + 1) {
        int ta = a[i] + b[n] - b[i - 1];
        ans = max(ans, ta);
    }
    cout << ans << nl;
}