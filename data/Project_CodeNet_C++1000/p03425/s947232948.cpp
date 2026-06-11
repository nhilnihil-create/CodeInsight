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

string s; 
ll m, a, r, c, h;
ll D[5];
int A[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2}; 
int B[10] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
int C[10] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    F0R(i, n) {
        cin >> s;
        if (s[0] == 'M') m++;
        if (s[0] == 'A') a++;
        if (s[0] == 'R') r++;
        if (s[0] == 'C') c++;
        if (s[0] == 'H') h++;
    }
    D[0] = m; D[1] = a; D[2] = r; D[3] = c; D[4] = h;
    ll ans = 0;
    F0R(i, 10) {
        ans += D[A[i]] * D[B[i]] * D[C[i]];
    }
    cout << ans << nl;
}