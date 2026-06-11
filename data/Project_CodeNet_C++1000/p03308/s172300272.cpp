#include <bits/stdc++.h>
using namespace std;
#define int long long int

void test()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ans = max(ans, abs(v[i] - v[j]));
        }
    }
    cout << ans << endl;
}
int32_t main()
{

    int t = 1;
    // cin >> t;
    while (t--)
    {
        test();
    }

    return 0;
}