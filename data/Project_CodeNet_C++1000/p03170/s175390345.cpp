#include<iostream>
#define ll long long
#define MOD 1000000007
using namespace std;
int dfs(int& n,int *arr,int k,int *dp)
{
    if(k<0)
        return false;
    if(dp[k]!=-1)
        return dp[k];
   
    bool myjj=false;
    for(int j=0;j<n;j++)
    {
        int temp_stones=k-arr[j];
        if(temp_stones>0)
        myjj=(myjj|(1-dfs(n,arr,temp_stones,dp)));
        else if(temp_stones==0)
            myjj=true;
    }
    dp[k]=myjj;
    return myjj;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int *dp=new int[k+1];
    
        for(int j=0;j<=k;j++)
            dp[j]=-1;
    
    int temp=dfs(n,arr,k,dp);
    if(temp==1)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
}
