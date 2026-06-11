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
    int n,m;
    cin>>n>>m;
    int a[m][2];
    for(int i=0;i<m;i++)cin>>a[i][0]>>a[i][1];
    int l=a[0][0],r=a[0][1];
    for(int i=0;i<m;i++)
    {
        l=max(l,a[i][0]);
        r=min(r,a[i][1]);
    }
    cout<<max(0,r-l+1)<<endl;
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
