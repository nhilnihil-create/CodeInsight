#include <bits/stdc++.h>
using namespace std;
bool dp[100005];
bool helper(vector<int> &v,int k,int n)
{
    //base case;
    if(k<=0)
    {
        return false;
    }
    if(dp[k]!=-1)
    {
        return dp[k];
    }
    bool ans=false;
    for(int i=0;i<n;i++)
    {

        if(v[i]==k)
        {
            return true;
        }
        if(k>=v[i])
        {
            ans=ans || !helper(v,k-v[i],n);
        }
    }
    return dp[k]=ans;
}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    memset(dp,false,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        dp[v[i]]=true;
    }

    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[j]<=i)
            {
                dp[i]=dp[i] || !dp[i-v[j]];
            }
        }
    }

    if(dp[k])
    {
        cout<<"First\n";
    }
    else
    {
        cout<<"Second\n";
    }
    return 0;
}
