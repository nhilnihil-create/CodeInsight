#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
#define pow10(n) int(1e##n + n)

void solve()
{
    int A, B, Q;
    cin >> A >> B >> Q;

    vector<LL> s(A);
    REP0 (i, A)
    {
        cin >> s[i];
    }
    s.push_back(LLINF);
    s.push_back(-LLINF);
    sort(s.begin(), s.end());

    vector<LL> t(B);
    REP0 (i, B)
    {
        cin >> t[i];
    }
    t.push_back(LLINF);
    t.push_back(-LLINF);
    sort(t.begin(), t.end());

    REP0 (i, Q)
    {
        LL x;
        cin >> x;

        // s を探索
        int ok = -1;
        int ng = A + 2;
        while (abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;
            if (s[mid] <= x)
                ok = mid;
            else
                ng = mid;
        }  // s[mid] : x 以下になる最大の s
        LL dsl = abs(s[ok] - x);
        LL dsr = abs(s[ng] - x);

        // t を探索
        ok = -1;
        ng = B + 2;
        while (abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;
            if (t[mid] <= x)
                ok = mid;
            else
                ng = mid;
        }  // t[mid] : x 以下になる最大の t
        LL dtl = abs(t[ok] - x);
        LL dtr = abs(t[ng] - x);

        LL ans = min(max(dtl, dsl), max(dtr, dsr));
        ans = min(ans, 2LL * min(dsl, dtr) + max(dsl, dtr));
        ans = min(ans, 2LL * min(dtl, dsr) + max(dtl, dsr));
        cout << ans << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
