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
    string s; cin >> s;
    int nel{}, ner{}, nwl{}, nwr{};
    trav(a, s) {
        if (a == 'E') ner++;
        else nwr++;
    }
    int ans = min(nel + ner, nwl + nwr);
    FOR(i, 0, s.size()) {
        if (i > 0) {
            if (s[i - 1] == 'E') nel++;
            else nwl++;
        }
        if (s[i] == 'E') ner--;
        else nwr--;
        ans = min(ans, nwl + ner);
    }
    cout << ans << nl;
}