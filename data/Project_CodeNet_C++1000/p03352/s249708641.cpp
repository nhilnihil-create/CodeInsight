#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void solve()
{
    int x;
    cin >> x;
    vector<int> a;
    a.push_back(1);
    for (int i = 2; i <= 1000; i++)
    {
        for (int j = i * i; j <= 1000; j *= i)
        {
            a.push_back(j);
        }
    }
    sort(a.begin(), a.end());
    int ans = 0;
    if (x == *lower_bound(a.begin(), a.end(), x))
        ans = x;
    else
        ans = a[lower_bound(a.begin(), a.end(), x) - a.begin() - 1];
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}