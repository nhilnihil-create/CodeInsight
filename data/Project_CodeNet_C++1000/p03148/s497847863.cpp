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
    LL N, K;
    cin >> N >> K;
    vector<vector<LL>> s(N);

    REP0 (i, N)
    {
        LL t, d;
        cin >> t >> d;
        --t;
        s[t].push_back(d);
    }

    for (auto &v : s)
    {
        sort(v.begin(), v.end(), [](LL a, LL b) { return a > b; });
        if (v.empty())  // 番兵により、操作上 N 種類選べるようにしておく
            v.push_back(-INTINF);
    }

    sort(s.begin(), s.end(), [&](vector<LL> a, vector<LL> b) { return a[0] > b[0]; });

    LL cur = 0;
    priority_queue<LL> PQ;  // 選ばれていない集合
    // まず K 種類選ぶ場合
    REP0 (i, K)
    {
        cur += s[i][0];
        for (int j = 1; j < s[i].size(); j++)
        {  // K種類選ぶとき、2つめ以降の要素は選ばれない
            PQ.push(s[i][j]);
        }
    }

    FOR (i, K, N)
        REP0 (j, s[i].size())
            PQ.push(s[i][j]);

    LL res = cur + K * K;
    // K-1種類以上 ~ 1種類以上までみていく
    for (LL x = K - 1; x >= 1; x--)
    {
        LL v = s[x][0];
        LL w = PQ.top();
        if (v < w)
        {
            PQ.pop();
            cur += w;
            PQ.push(v);
            cur -= v;
        }
        res = max(res, cur + x * x);
    }
    cout << res << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
