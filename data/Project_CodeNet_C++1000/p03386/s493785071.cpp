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
    int a,b,k;
    cin>>a>>b>>k;k--;
    if(a+k>=b-k)
    {
        for(int i=a;i<=b;i++)cout<<i<<endl;
        return;
    }
    else
    {
        for(int i=a;i<=a+k;i++)cout<<i<<endl;
        for(int i=b-k;i<=b;i++)cout<<i<<endl;
    }
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
