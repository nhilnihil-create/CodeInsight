#include <bits/stdc++.h>
using namespace std;

long long maxll(long long a, long long b){return a > b ? a : b;}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<long long> aa(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        aa[i + 1] = aa[i] + a[i];
    }

    vector<pair<int,int>> bc(m);
    for (int i = 0; i < m; i++)
    {
        int b, c;
        cin >> b >> c;
        bc[i] = make_pair(c, b);
    }
    sort(bc.begin(), bc.end());
    reverse(bc.begin(), bc.end());

    vector<long long> cc(n + 1, 0);
    int iter = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < bc[i].second; j++)
        {
            cc[iter + 1] = cc[iter] + bc[i].first;
            if(iter == n)break;
            iter++;
        }
        if(iter == n)break;
    }
/*
    for (int i = 0; i < n + 1; i++)cout << aa[i] << " ";
    cout << endl;
    for (int i = 0; i < n + 1; i++)cout << cc[i] << " ";
    cout << endl;
*/
    long long ans = 0;
    for (int i = 0; i <= n; i++)
    {
        //cout << -aa.at(i) + cc.at(i) + aa.at(n) << " ";
        ans = maxll(ans, -aa.at(i) + cc.at(i) + aa.at(n));
    }
    cout << ans << endl;
}