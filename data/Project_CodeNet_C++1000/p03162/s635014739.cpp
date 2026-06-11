#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n , a[N] , b[N] , c[N] , f[N][5];

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    f[0][1] = 0;
    f[0][2] = 0;
    f[0][3] = 0;
    for(int i = 1 ; i <= n; ++i)
    {
        f[i][1] = max(f[i-1][2] , f[i-1][3]) + a[i];
        f[i][2] = max(f[i-1][1] , f[i-1][3]) + b[i];
        f[i][3] = max(f[i-1][1] , f[i-1][2]) + c[i];
        //cout << f[i][1] << " " << f[i][2] << " " << f[i][3] << endl;
    }
    cout << max(f[n][1] , max(f[n][2] , f[n][3]));
    return 0;
}
