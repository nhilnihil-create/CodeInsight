#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007
#define INF (1 << 30)
#define REP(i, m, n) for(int i = (int)m; i < (int)n; ++i)
#define rep(i, n) REP(i, 0, n)


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b; cin >> n >> a >> b;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    rep(i, n) {
        int p; cin >> p;
        if(p <= a) cnt1++;
        else if(p <= b) cnt2++;
        else cnt3++;
    }
    cout << min({cnt1, cnt2, cnt3}) << '\n';
    return 0;
}