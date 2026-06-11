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

void solve() {
    int N;
    ll X;
    cin >> N >> X;
    vi C{ 5 };
    if (N >= 2) {
        C.push_back(5);
    }
    for (int i = 3; i <= N; ++i) {
        C.push_back(C.back()+2);
    }

    vi xx(N);
    rep(i, N) {
        cin >> xx[i];
    }
    reverse(all(xx));
    vll sm(N + 1);
    rep(i, N) {
        sm[i + 1] = sm[i] + xx[i];
    }

    ll ans = LLONG_MAX / 3;
    for (int i = 1; i <= N; ++i) {
        ll x = N * X + X * i;
        for (int j = 0, k = 0; k < N; ++j) {
            int nk = min(N, k + i);
            x += (sm[nk] - sm[k])*C[j];
            if (x >= ans) {
                break;
            }
            k = nk;
        }
        smin(ans, x);
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