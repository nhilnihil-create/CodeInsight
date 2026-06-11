// ------------------------------
//   Author: Subhashis Suara
// ------------------------------

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, cnt = 0, minT = 101;
    cin >> n >> m >> x;
    int toll[m];
    for (int i = 0; i < m; i++)
        cin >> toll[i];
    
    for (int i = 0; i < x; i++)
        for (int j = 0; j < m; j++)
            if (i + 1 == toll[j])
                cnt++;
    // cout << cnt << "\n";
    minT = min(minT, cnt);
    cnt = 0;
    for (int i = x; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i + 1 == toll[j])
                cnt++;
    // cout << cnt << "\n";
    minT = min(minT, cnt);
    cout << minT << "\n";
    return 0;
}
