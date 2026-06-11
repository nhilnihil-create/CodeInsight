#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m,c,ans=0,sum=0;
    cin >> n >> m >> c;
    ll a[n][m];
    ll b[m];
    for(ll i=0;i<m;i++)
    {
        cin >> b[i];
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            sum = a[i][j]*b[j] + sum;
        }
        if(sum +c>0)
        {
            ans++;
        }
        sum = 0;
    }
    cout << ans << endl;
}
