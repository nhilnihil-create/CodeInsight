#include<bits/stdc++.h>
using namespace std;
int dp[3001][3001];



int lenlcs(string &s,string &t,int i,int j)
{
    int n=s.size();
    int m=t.size();
    if(i>=n || j>=m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    else
    {
        if(s[i]==t[j])
        return dp[i][j]=1+lenlcs(s,t,i+1,j+1);

        else{
            int x=lenlcs(s,t,i,j+1);
            int y=lenlcs(s,t,i+1,j);
            return dp[i][j]=max(x,y);
        }
    }

}
string solve(string &s,string &t)
{
    memset(dp,-1,sizeof dp);
    int len=lenlcs(s,t,0,0);
    string ans;
    if(len==0)
        return ans;
        int i=0,j=0;
        while(len>0)
        {
           if(s[i]==t[j])
           {
               len--;
               ans.push_back(s[i]);
               i++;
               j++;


           }
           else
           {
               if(dp[i][j+1]>dp[i+1][j])
                j++;
               else
                i++;

           }

        }
        return ans;

}

int main()
{

    string s,t;
    cin>>s;
    cin>>t;
    cout<<solve(s,t);

    return 0;

}
