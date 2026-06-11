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
    int n=s.length(),ans=INT_MAX;
    for(int i=0;i<n-2;i++)
    {
        string curr="";curr+=s[i];curr+=s[i+1];curr+=s[i+2];
        int num=stoi(curr);
        ans=min(ans,abs(753-num));
        //cout<<abs(753-num)<<" "<<num<<" "<<curr<<" "<<ans<<endl;
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
