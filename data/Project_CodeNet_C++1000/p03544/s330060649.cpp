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
    int n;
    cin>>n;
    if(n==0)
    cout<<2<<endl;
    else if(n==1)
    cout<<1<<endl;
    else
    {
        long long int a=2,b=1,pre=0;
        for(int i=2;i<=n;i++)
        {
            pre=a+b;
            a=b;
            b=pre;
        }
        cout<<pre;
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
