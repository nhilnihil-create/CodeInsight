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
bool rev(long long int a,long long int b)
{
    if(a>b)return true;
    else return false;
}
bool compa(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    if(a.first==b.first)
    {
        if(a.second.first>b.second.first)
        return true;
        else
        return false;
    }
    if(a.first<b.first)
    return true;
    else 
    return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    long long int n;cin>>n;
    long long int a[n],b[n];
    for(long long int i=0;i<n;i++)cin>>a[i];for(long long int i=0;i<n;i++)cin>>b[i];
    long long int ans=0,v=0;
    for(long long int i=0;i<n;i++)
    {
        ans=0;
        for(long long int j=0;j<=i;j++)
        ans+=a[j];
        for(long long int j=i;j<n;j++)
        ans+=b[j];
        v=max(ans,v);
    }
    cout<<v;
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
