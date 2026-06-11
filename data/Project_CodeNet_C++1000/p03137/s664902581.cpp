#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , m, ans = 0;
    cin >> n >> m;
    long long int x[m];
    for (int i = 0; i < m; i++)
        cin >> x[i];
    sort(x, x+m);
    long long int y[m-1];
    if (m == 1 || n >= m)
    {    
        cout << 0 << endl;
        return (0);
    }
    for (int i=0; i < m-1; i++)
        y[i]=x[i+1] - x[i];
    sort(y, y+m-1);
    for (int i = 0; i < m - n; i++)
        ans+=y[i];
    cout << ans << endl;
}