#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, ans = 0;

    cin >> n >> m;
    vector<int> x(m);
    vector<int> L;
    cin >> x[0];
    for (int i = 1; i < m; i++)
    {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    for (int i = 1; i < m; i++)
    {
        L.push_back(x[i] - x[i - 1]);
    }
    sort(L.begin(), L.end());
    if (m == 1)
    {
        ans = 0;
    }
    else
    {
        for (int i = 0; i <= m - 1 - n; i++)
        {
            // cout << L[i] << endl;
            ans += L[i];
        }
    }
    cout << ans << endl;
    return 0;
}
