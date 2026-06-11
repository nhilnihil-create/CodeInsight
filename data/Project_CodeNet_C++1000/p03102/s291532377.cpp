#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n,m,c;
    cin >> n >> m >> c;
    int a[n][m];
    int b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int D = c;
        for (int j = 0; j < m; j++)
        {
            D += a[i][j] * b[j];
        }
        if (D>0)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
