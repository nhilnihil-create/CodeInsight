#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> c(5);
    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        c[a]++;
        c[b]++;
    }
    int k = 0, t = 0;
    for (int i = 1; i <= 4; i++)
    {
        if (c[i] == 1) k++;
        if (c[i] == 2) t++;
    }
    if (k == 2 && t == 2) cout << "YES";
    else cout << "NO";
}
