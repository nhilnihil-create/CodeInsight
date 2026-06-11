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
    long long int n,x;
    cin>>n>>x;
    long long int a[n];
    for(long long int i=0;i<n;i++)cin>>a[i];
    long long int ans=0;
    sort(a,a+n);
    for(long long int i=0;i<n;i++)
    {
        if(a[i]<=x){if(i==n-1)
        {if(a[i]==x)ans++;
        break;}
        x-=a[i];ans++;}
        else break;
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
