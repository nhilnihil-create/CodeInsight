#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> l(n + 1, 0), r(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
        {
            l[i + 1] = l[i] + 1;
            r[i + 1] = r[i];
        }
        else
        {
            r[i + 1] = r[i] + 1;
            l[i + 1] = l[i];
        }
    }

    int ans = 1001001001;
    for (int i = 1; i < n + 1; i++)
    {
        ans = min(ans, l[i - 1] + r[n] - r[i]);
    }
    cout << ans << '\n';
}
