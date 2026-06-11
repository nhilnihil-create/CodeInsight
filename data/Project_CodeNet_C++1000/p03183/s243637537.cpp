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

struct P {
    int w, s, v;
};
bool cf(P a, P b) {
    return min(a.s - b.w, b.s) > min(b.s - a.w, a.s);
}

void solve() {
    int N;
    cin >> N;
    vector<P> A;
    rep(i, N) {
        P p;
        cin >> p.w >> p.s >> p.v;
        A.push_back(p);
    }

    sort(all(A), cf);

    const int W = 20002;
    const ll MI = LLONG_MIN / 3;
    vector<ll> dp(W, MI);
    dp[W - 1] = 0;

    rep(i, N) {
        P p = A[i];
        FOR(j, p.w, W)if (dp[j] != MI) {
            int nj = min(j - p.w, p.s);
            smax(dp[nj], dp[j] + p.v);
        }
    }
    
    ll ans = *max_element(all(dp));
    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}