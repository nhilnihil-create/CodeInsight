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
    long long int n;
    cin>>n;
    long long int ans=INT_MAX,curr=0;
    long long int a[n];
    for(auto &x:a)cin>>x;
    for(auto x:a)
    {
        curr=0;
        while(x%2==0)
        {
            x/=2;
            curr++;
        }
        ans=min(ans,curr);
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
