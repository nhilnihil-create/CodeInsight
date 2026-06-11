#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int k = -1;
    for (int i = 1; i * (i - 1) / 2 <= n; i++)
    {
        if (i * (i - 1) / 2 == n)
            k = i;
    }
    if (k == -1)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << k << endl;
    vector<vector<int>> s(k);
    int num = 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            s[i].push_back(num);
            s[j].push_back(num);
            num++;
        }
    }
    rep(i, k)
    {
        cout << s[i].size() << " ";
        rep(j, s[i].size()) cout << s[i][j] << " ";
        cout << endl;
    }
}