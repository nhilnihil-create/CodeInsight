#include<iostream>
#include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
#define lli long long int
#define all(v) (v.begin(),v.end())
#define fr first
#define sc second
#define mp make_pair
using namespace std;
string a,b;
lli dp[3005][3005];
lli rec(int n1,int n2)
{
    if(n1==0||n2==0) return dp[n1][n2]=0;
    if(dp[n1][n2]!=-1) return dp[n1][n2];
    if(a[n1-1]==b[n2-1]) return dp[n1][n2]=1+rec(n1-1,n2-1);
    return dp[n1][n2]=max(rec(n1,n2-1),
               rec(n1-1,n2));
}
int main()
{
    cin>>a>>b;
    int i,j;
    int n1=a.size();
    int n2=b.size();
    memset(dp,-1,sizeof(dp));

    lli y=rec(n1,n2);
    i=n1;j=n2;
    string s="";
    while(i>0&&j>0)
    {
        if(a[i-1]==b[j-1])
        {
            s=a[i-1]+s;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else j--;
    }
    cout<<s;


}
