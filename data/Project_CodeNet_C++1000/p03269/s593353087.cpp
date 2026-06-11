#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int l;
    cin >> l;
    int n = 1;
    while(n < 20 && l >= pow(2, n))
    {
        n++;
    }

    vector<vector<int>> edge;
    int mmax = pow(2, n-1) - 1;
    int diff = l-1;
    for(int i = n-1; i > 0; i--)
    {
        int tmp = diff - pow(2, i-1) + 1;
        if(tmp > mmax)
        {
            edge.push_back({i, n, tmp});
            diff = tmp - 1;
        }
    }

    cout << n << " " << 2 * (n-1) + edge.size() << endl;
    for(int i = 1; i < n; i++)
    {
        cout << i << " " << i+1 << " " << pow(2, i-1) << endl;
        cout << i << " " << i+1 << " " << 0 << endl;
    }
    for(int i = 0; i < edge.size(); i++)
    {
        vector<int> ans = edge[i];
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }
}
