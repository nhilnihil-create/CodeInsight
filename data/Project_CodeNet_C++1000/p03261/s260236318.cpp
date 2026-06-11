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
    map<string,int>mp;
    string prev;
    cin>>prev;
    mp[prev]=1;
    for(int i=1;i<n;i++)
    {
        string s;
        cin>>s;
        if(s[0]!=prev[prev.length()-1])
        {
            cout<<"No";return;
        }
        prev=s;
        if(mp[prev]==1)
        {
            cout<<"No";return;
        }
        else
        mp[prev]=1;
    }
    cout<<"Yes";
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
