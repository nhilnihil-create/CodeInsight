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
    cin >> N;
    int K = 2;
    for (; K*(K - 1) / 2 < N; ++K) {
    }
    if (K*(K - 1) / 2 != N) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    cout << K << endl;
    vector<vi> ans(K);
    int cur = 1;
    rep(i, K) {
        rep(j, i) {
            ans[i].push_back(cur);
            ans[j].push_back(cur);
            cur++;
        }
    }
    rep(i, K) {
        cout << sz(ans[i]);
        each(a, ans[i])cout << ' ' << a;
        cout << endl;
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	solve();
	return 0;
}