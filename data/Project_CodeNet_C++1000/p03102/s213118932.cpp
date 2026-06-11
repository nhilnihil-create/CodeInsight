#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> bs(m);
    for(int i=0; i<m; i++) cin >> bs.at(i);
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int sun = c;
        for(int j=0; j<m; j++)
        {
            int a;
            cin >> a;
            sun += a*bs.at(j);
        }
        if(sun > 0) ans++;
    }
    cout << ans << endl;

    return 0;
}
