#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, T;
    cin >> n >> T;
    int c[n], t[n];
    for (int i = 0; i < n; ++i)
        cin >> c[i] >> t[i];
    int cost(-1);
    for (int i = 0; i < n; ++i)
    {
        if ((cost < 0 || c[i] < cost) && t[i] <= T)
        {
            cost = c[i];
        }
    }
    if (cost > 0)
        cout << cost << endl;
    else
    {
        cout << "TLE" << endl;
    }
}