#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(100000), b(100000);
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        if (i % 2 == 0)
        {
            a[s - 1].first++;
            a[s - 1].second = s - 1;
        }
        if (i % 2 != 0)
        {
            b[s - 1].first++;
            b[s - 1].second = s - 1;
        }
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    if (a[0].second == b[0].second)
    {
        if (a[0].first + b[1].first < a[1].first + b[0].first)
            cout << (n - a[1].first - b[0].first) << endl;
        else
        {
            cout << (n - a[0].first - b[1].first) << endl;
        }
    }
    else
    {
        cout << n - a[0].first - b[0].first << endl;
    }
}