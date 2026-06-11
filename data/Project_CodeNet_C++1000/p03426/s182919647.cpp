// AtCoder Beginner Contest 089 - Problem D: Practical Skill Test (https://atcoder.jp/contests/abc089/tasks/abc089_d)
#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 310 };

vector<ii> as(MAX*MAX);

vector<int> solve(int H, int W, int D, const vector<ii>& qs)
{
    vector<vector<int>> ps(D + 1);

    for (int x = 1; x <= D; ++x)
    {
        ps[x].push_back(0);
//cout << "-- x = " << x << " (" << as[x].first << ", " << as[x].second << ")" << endl;
        for (int y = x + D; y <= H*W; y += D)  
        {
            int dist = abs(as[y - D].first - as[y].first) + abs(as[y - D].second - as[y].second);
            ps[x].push_back(dist + ps[x].back());
//cout << "y = " << y << " (" << as[y].first << ", " << as[y].second << "), d = " << dist << ", ps = " << ps[x].back() << endl;
        }
    }

    vector<int> ans;

    for (auto q : qs)
    {
        auto L = q.first, R = q.second;

        auto r = (L % D) == 0 ? D : L % D;
        auto a = (L - r) / D, b = (R - r) / D;
        auto sum = ps[r][b] - ps[r][a];
        ans.push_back(sum);
//cout << "L = " << L << ", R = " << R << ", r = " << r << ", a = " << a << ", b = " << b << endl;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int H, W, D;
    cin >> H >> W >> D;    

    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j)
        {
            int a;
            cin >> a;

            as[a] = ii(i, j);
        }

    int Q;
    cin >> Q;

    vector<ii> qs(Q);

    for (int i = 0; i < Q; ++i)
        cin >> qs[i].first >> qs[i].second;

    auto ans = solve(H, W, D, qs);

    for (auto x : ans)
        cout << x << endl;

    return 0;
}
