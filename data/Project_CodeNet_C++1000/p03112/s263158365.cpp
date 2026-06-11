#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

int main()
{
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<long long> s(A + 2), t(B + 2);
    vector<pair<long long, int>> x(Q);
    long long INF = INT64_MAX / 10;
    s[0] = -INF;
    t[0] = -INF;
    s.back() = INF;
    t.back() = INF;
    rep(i, A)
    {
        cin >> s[i + 1];
    }
    rep(i, B)
    {
        cin >> t[i + 1];
    }
    rep(i, Q)
    {
        cin >> x[i].first;
        x[i].second = i;
    }
    SORT(x);
    vector<long long> ans(Q);
    int i_A = 0, i_B = 0;
    rep(i, Q)
    {
        long long pos = x[i].first;
        while (!(s[i_A] < pos && pos < s[i_A + 1]))
            i_A++;

        while (!(t[i_B] < pos && pos < t[i_B + 1]))
            i_B++;

        long long LA = s[i_A], RA = s[i_A + 1], LB = t[i_B], RB = t[i_B + 1];

        long long dist0 = pos - min(LA, LB);
        long long dist1 = RA - LB + min(RA - pos, pos - LB);
        long long dist2 = RB - LA + min(RB - pos, pos - LA);
        long long dist3 = max(RA, RB) - pos;
        ans[x[i].second] = min({dist0, dist1, dist2, dist3});
    }
    rep(i, Q)
    {
        cout << ans[i] << endl;
    }
    return 0;
}