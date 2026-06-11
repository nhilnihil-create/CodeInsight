#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> p(m), y(m);
    for (int i = 0; i < m; i++)
    {
        cin >> p[i] >> y[i];
    }
    
    vector<int> py[n + 1];
    for (int i = 0; i < m; i++)
    {
        py[p[i]].push_back(y[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(py[i].begin(), py[i].end());
    }
    
    for (int i = 0; i < m; i++)
    {
        printf("%06d", p[i]);
        printf("%06d\n", (long long)(lower_bound(py[p[i]].begin(), py[p[i]].end(), y[i]) - py[p[i]].begin()) + 1);
    }


}