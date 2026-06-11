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

int N, Q, K[75];
ll D[75], M[75], DM[75], ans[75];
string S;

void solve() {
    cin >> N >> S >> Q;
    rep(i, Q)cin >> K[i];

    rep(i, N) {
        char c;
        rep(j, Q) {
            if (i >= K[j]) {
                c = S[i - K[j]];
                if (c == 'D') {
                    D[j]--;
                    DM[j] -= M[j];
                } else if (c == 'M') {
                    M[j]--;
                }
            }
        }

        c = S[i];
        rep(j, Q) {
            if (c == 'D') {
                D[j]++;
            } else if (c == 'M') {
                M[j]++;
                DM[j] += D[j];
            } else if (c == 'C') {
                ans[j] += DM[j];
            }
        }
    }

    rep(j, Q)cout << ans[j] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}