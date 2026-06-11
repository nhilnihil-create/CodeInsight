#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    long long int n,m,c;
    cin>>n>>m>>c;
    long long int b[m];
    for(long long int i=0;i<m;i++)cin>>b[i];
    long long int a[n][m];
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<m;j++)cin>>a[i][j];
    }
    long long int value=0,ans=0;
    for(long long int i=0;i<n;i++)
    {
        value=0;
        for(long long int j=0;j<m;j++)value+=a[i][j]*b[j];
        value+=c;
        if(value>0)ans++;
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    while(t--)
    {
        solve();
    }
}
