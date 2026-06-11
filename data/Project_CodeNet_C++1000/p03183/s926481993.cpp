#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define REP(i,n) for (int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()

const int MAX = 2e4+10;
struct block {
    int w, s, v;

    bool operator<( const block& right ) const {
        return s+w > right.s+right.w;
    }
};
vector<block> B;
ll dp[MAX];

int N;

int main () {
	cin >> N;
    B = vector<block>(N);
    REP (i, N) cin >> B[i].w >> B[i].s >> B[i].v;
    sort(ALL(B));

    ll ans = 0;
    REP (i, N) {
        REP (j, B[i].s+1)
            dp[j] = max(dp[j], dp[j+B[i].w]+B[i].v);
    }
    REP (i, MAX) ans = max(ans, dp[i]);
    cout << ans << endl;
}