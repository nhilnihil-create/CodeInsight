#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(m, 1);
    for (size_t i = 0; i < n; i++)
    {
        int k,input;
        vector<int> aa(m, 0);
        cin >> k;
        for (size_t j = 0; j < k; j++)
        {
            cin>>input;
            aa[input - 1] = 1;

            /* code */
        }
        for (size_t j = 0; j < m; j++)
        {
            a[j] = (a[j] & aa[j]);
        }
    }
    int ans=0;
    for (size_t i = 0; i < m; i++)
    {
        ans += a[i];
    }
    cout << ans << endl;

    return 0;
}