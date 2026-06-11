#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
pair<int, int> res[(1 << 18)][2];

int main()
{
    cin >> n;
    m = (1 << n) - 1;
    for (int i = 0; i <= m; i++) cin >> res[m - i][0].first, res[m - i][0].second = m - i, res[m - i][1].second = m - i;
    int ans = 0;
    for (int i = m; i >= 0; i--)
    {
        vector<pair<int, int> > v;
        for (int j = 0; j < n; j++)
        {
            if (!((1 << j) & i)) v.push_back(res[(1 << j) | i][0]);
            if (!((1 << j) & i)) v.push_back(res[(1 << j) | i][1]);
        }
        v.push_back(res[i][0]);
        v.push_back(res[i][1]);
        sort(v.begin(), v.end());
        v.resize(unique(v.begin(), v.end()) - v.begin());
        reverse(v.begin(), v.end());
        res[i][0] = v[0];
        res[i][1] = v[1];
        if (m - i)
            ans = max(ans, res[i][0].first + res[i][1].first), cout << ans << "\n";
    }
}
