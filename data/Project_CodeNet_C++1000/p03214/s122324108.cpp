#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

#define int long long

signed main()
{
    int n;
    vector<int> a;

    cin >> n;

    a.resize(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int ans = n - 1;
    int sum = accumulate(a.begin(), a.end(), 0);

    for(int i = n - 2; i >= 0; --i)
    {
        if(abs(sum - a[i] * n) <= abs(sum - a[ans] * n))
        {
            ans = i;
        }
    }

    cout << ans << endl;
}