#include <bits/stdc++.h>
using namespace std;
#define int long long int

void test()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (k >= n)
    {
        cout << 1 << endl;
    }
    else
    {
        n--, k--;
        cout << ceil(n / (k * 1.0)) << endl;
    }
    
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