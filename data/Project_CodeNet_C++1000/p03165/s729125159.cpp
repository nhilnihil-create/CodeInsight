#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
const int N=3000+5,mod=1e9+7;
typedef long long ll;
int n1,n2,dp[N][N];
string s1,s2;
int solve(int i=0,int j=0){
    if(i==n1 || j==n2)return 0;
    int &ret=dp[i][j];
    if(~ret)return ret;
    if(s1[i]==s2[j])return ret=1+solve(i+1,j+1);
    ret=solve(i+1,j);
    ret=max(ret,solve(i,j+1));
    return ret;

}
string ans="";
void build(int i=0,int j=0){
    if(i==n1 || j==n2)return ;
    int &ret=dp[i][j];

    if(s1[i]==s2[j]){
        ans+=s1[i];
        build(i+1,j+1);
        return ;
    }
    int ch1=solve(i+1,j);
    int ch2=solve(i,j+1);
    if(ch1==ret)
        build(i+1,j);
    else build(i,j+1);

}
int main()
{
    Elhabashy
    input();
    cin>>s1>>s2;
    n1=s1.length();n2=s2.length();
    memset(dp,-1,sizeof dp);
    int x=solve();
    build();
    cout<<ans<<endl;
}
