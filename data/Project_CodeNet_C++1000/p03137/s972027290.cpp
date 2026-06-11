#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    if( n>= m)
    {
        cout<<0;
        return 0;
    }
    sort( a , a+m);
    int d [m-1];
    ll total =0;
    for(int i=0;i<m-1;i++ )
    {
        d[i] = a[i+1]- a[i];
        total += d[i];
    }
    sort( d , d+m-1);
    for(int i=0;i<n-1;i++)
    {
        total = total - d[m-1 -i - 1];
    }
    cout<<total ;
}