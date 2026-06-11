#include<bits/stdc++.h>
using namespace std;
// << left shift *2 and >>right shift /2
long long int mod97=1000000007;
double pi=3.1415926536;
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
long long int dp[4000][4000];
long long int c[4000][4000];//0 mtlb i-1,j   1 mtlb i,j-1   2 mtlb i-1,j-1
void solve()
{
    string s,t;cin>>t>>s;long long int m=s.size(),n=t.size();
    if(s[0]==t[0])dp[0][0]=1,c[0][0]=2;
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<m;j++)
        {
            // s ka char na lu
            if(i>0)
            dp[i][j]=dp[i-1][j],c[i][j]=0;
            // t ka char na lu
            if(j>0)
            if(dp[i][j-1]>dp[i][j])
            dp[i][j]=dp[i][j-1],c[i][j]=1;
            // agr dono same to dono lu
            if(i>0 && j>0 && s[j]==t[i] && dp[i-1][j-1]+1>=dp[i][j])
            dp[i][j]=1+dp[i-1][j-1],c[i][j]=2;
            else if(s[j]==t[i] )
            dp[i][j]=1,c[i][j]=2;
        }
    }
    string ans="";
    long long int i=n-1,j=m-1;
    while(i>=0 && j>=0)
    {
        if(c[i][j]==0)
        i--;
        else if(c[i][j]==1)
        j--;
        else
        {
            ans+=s[j],i--,j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;
    //cin>>t;long long int temp=t;
    while(t--)
    {
        //cout<<"Case "<<temp-t<<": ";
        solve();
    }
}
