#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, res=INT_MAX;
    cin >> n >> k;
  
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i <= n - k; ++i)
    {
        res = min(res, v[i + k - 1] - v[i]);
    }

    cout << res << "\n";
    return 0;
}