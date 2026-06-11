#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define MT make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define RT return
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

map<pii, int> f(string s) {
    static const int C = 31, C2 = 29, P = 1000000007, P2 = 1000000009;
    map<pii, int> res;
    int n = sz(s);
    rep(S, 1 << n) {
        ll h = 0, h2 = 0;
        rep(i, n) {
            if (S >> i & 1) {
                h = (h*C + s[i]) % P;
            } else {
                h2 = (h2*C2 + s[i]) % P;
            }
        }
        res[mp((int)h, (int)h2)]++;
    }
    return res;
}

void solve() {
    int N;
    string S;
    cin >> N >> S;
    string L = S.substr(0, N), R = S.substr(N, N);
    reverse(all(R));

    auto X = f(L);
    auto Y = f(R);
    ll ans = 0;
    each(x, X) {
        ans += (ll)x.second * Y[x.first];
    }
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}