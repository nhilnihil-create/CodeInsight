// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> t(n), x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }

    int time = 0;
    int dx = 0, dy = 0;
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        time = t[i] - time;
        dx = abs(x[i] - dx);
        dy = abs(y[i] - dy);
        if (time < dx + dy || time % 2 != (dx + dy) % 2)
        {
            flag = false;
        }
    }

    cout << ((flag) ? "Yes" : "No") << '\n';
    return (0);
}
