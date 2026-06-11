#include <bits/stdc++.h>
using namespace std;
// map<pair<int,int>,string> dp;
vector<vector<int>> dp(3003,vector<int>(3003,-1));
int n,m;
string s,t;
void find(int i,int j,int cnt,string str)
{
     if(cnt==0&&(i>=n||j>=m))
     {
         cout<<str;
         exit(0);
     }
     if(i>=n||j>=m)
     return;
     if(dp[i][j]!=cnt)
     return;
     if(s[i]==t[j])
     find(i+1,j+1,cnt-1,str+s[i]);
     else{
         find(i+1,j,cnt,str);
         find(i,j+1,cnt,str);
     }
}
int solve(int i,int j)
{
    if(i>=n||j>=m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans = 0;
    if(s[i]==t[j])
    ans = max(ans,1+solve(i+1,j+1));
    else{
    ans = max(ans,solve(i+1,j));
    ans = max(ans,solve(i,j+1));
    }
     return dp[i][j]=ans;
}
int main() {
    cin>>s>>t;
    n = s.length();
    m = t.length();
    int cnt = solve(0,0);
    find(0,0,cnt,"");
}
