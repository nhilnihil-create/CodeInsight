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
    string s;
    cin>>s;
    int n=s.length();
    int ans1=0,ans2=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(s[i]=='1')
            ans1++;
        }
        else
        {
            if(s[i]=='0')
            ans1++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(s[i]=='0')
            ans2++;
        }
        else
        {
            if(s[i]=='1')
            ans2++;
        }
    }
    cout<<min(ans1,ans2);
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
