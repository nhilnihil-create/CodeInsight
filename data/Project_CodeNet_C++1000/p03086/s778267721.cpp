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
    long long int curr=0,flag=0,ans=INT_MIN;
    long long int i=0,n=s.length();
    while(i<n)
    {
        if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T')
        break;
        else i++;
    }
    if(i==n)
    {
        cout<<"0";return;
    }
    flag++;
    for(i;i<s.length();i++)
    {
        
        if((s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T') && flag==1)
        curr++;
        else if((s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T') && flag==0)
        {curr=1;flag=1;}
        else
        {
            ans=max(ans,curr);curr=0;flag=0;
        }
        //cout<<flag<<" "<<curr<<" "<<ans<<" "<<i<<endl;
    }
    ans=max(ans,curr);
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
