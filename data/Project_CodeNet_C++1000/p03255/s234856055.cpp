#include<bits/stdc++.h>
using namespace std;

#define FOR(a, b, c) for(int a = b; a <= c; ++a)
#define FORW(a, b, c) for(int a = b; a >= c; --a)
#define fi first
#define se second
#define pb push_back
#define int long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int N = 2e5 + 100;
const int oo = 1e18;
const int mod   = 1e9 + 7;

int n, cost, ans = oo;
int pos[N];

signed main()  {
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(false); cout.tie(0);
    cin >> n >> cost;
    FOR(i, 1, n) cin >> pos[i];
    FORW(i, n, 1) pos[i] += pos[i + 1];

    FOR(group, 1, n) {
        int cnt = 1, cur = 0, rig = n;
        while(rig > 0 && cur + group * cost < ans) {
            int lef = max(1ll, rig - group + 1);
            if(cnt == 1) cur = 5 * (pos[lef] - pos[rig + 1]);
            else cur += (2 * cnt + 1) * (pos[lef] - pos[rig + 1]);
            cnt += 1;
            rig = lef - 1;
        }
        ans = min(ans, cur + group * cost);
    }
    cout << ans + cost * n;
}
