#include<bits/stdc++.h>

using namespace std;

const int N=1e5+7;
int n , a[N][3] ,f[N][3] ;

int main()
{
    cin >> n ;
    for(int i=1 ; i<=n ; i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    f[1][1]=a[1][1];
    f[1][2]=a[1][2];
    f[1][3]=a[1][3];

    for(int i=2 ; i<=n ; i++)
    {
        f[i][1]=max(f[i-1][2]+a[i][1] , f[i-1][3]+a[i][1]);
        f[i][3]=max(f[i-1][2]+a[i][3] , f[i-1][1]+a[i][3]);
        f[i][2]=max(f[i-1][1]+a[i][2] , f[i-1][3]+a[i][2]);
    }
    cout << max(f[n][1] , max(f[n][2] , f[n][3]));
}
