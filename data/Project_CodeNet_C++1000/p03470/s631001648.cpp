#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    sort(d, d + n, greater<int>());
    int cur = 101, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur > d[i])
        {
            ans++;
            cur = d[i];
        }
    }
    cout << ans << endl;
}
