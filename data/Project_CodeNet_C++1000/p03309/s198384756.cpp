#include <bits/stdc++.h>
using namespace std;
#define int long long int

void test()
{
    int n;
    cin >> n;
    vector<int> v(n), B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        B[i] = v[i] - i - 1;
    }
    sort(B.begin(), B.end());
    int med = 0;
    if (n % 2 != 0)
    {
        med = B[n / 2];
    }
    else
        med = (B[n / 2] + B[n / 2 - 1]) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += abs(v[i] - (med + i + 1));
    }
    cout << sum << endl;
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