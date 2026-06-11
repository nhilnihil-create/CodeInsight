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
    vector<int> t(n), x(n), y(n);
    F0R(i, n) cin >> t[i] >> x[i] >> y[i];
    bool works = true;
    int cx{}, cy{}, ct{};
    F0R(i, n) {
        int distreq = abs(x[i] - cx) + abs(y[i] - cy);
        int timedelta = t[i] - ct;
        if (distreq > timedelta || (((distreq ^ timedelta) & 1) != 0)) {
            works = false;
            break;
        }
        ct = t[i];
        cx = x[i];
        cy = y[i];
    }
    cout << (works ? "Yes" : "No") << nl;
}