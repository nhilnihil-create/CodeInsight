#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int S=s.size();
    int T=t.size();
    vector<vector<int>> dp(S+1,vector<int> (T+1,0));
    for(int i=0;i<s.size()+1;i++)
    {
        for(int j=0;j<t.size()+1;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            } 
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // for(int i=0;i<S+1;i++)
    // {   
    //     for(int j=0;j<T+1;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    string ans="";
    bool flag=1;
    for(int i=S;i>0;)
    {
        for(int j=T;j>0;)
        {
            if(s[i-1]==t[j-1])
            {
                ans+=s[i-1];
                i--;
                j--;
            }
            else 
            {
                if(i==0||j==0)
                {
                    break;
                    flag=0;
                }
                if(dp[i][j-1]>dp[i-1][j])
                {
                    j--;
                }
                else
                {
                    i--;
                }
            }
            if(i==0||j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        break;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}