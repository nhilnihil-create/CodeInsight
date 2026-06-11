#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int recur(int n,vector<int>op,vector<int>&dp)
{
    if(n==0||dp[n]!=-1)
    {
        return dp[n];
    }
    else
    {
        int min=INT_MAX;
        for(int i=0;i<op.size();i++){
            if(op[i]<=n){
                int result=recur(n-op[i],op,dp)+1;
                if(min>result){
                    min=result;
                }
            }
        }
        dp[n]=min;
        return dp[n];
    }
}


int main(){
    int n;
    cin>>n;
    vector<int>op;
    vector<int>dp(n+1,-1);
    dp[0]=0;
    op.push_back(1);
    int element=6;
    while(element<=n)
    {
        op.push_back(element);
        element*=6;
    }
    element=9;
    while(element<=n)
    {
        op.push_back(element);
        element*=9;
    }
    recur(n,op,dp);
    cout<<dp[n];
}