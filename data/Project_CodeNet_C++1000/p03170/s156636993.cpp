#include<bits/stdc++.h>
using namespace std;
int dp[100004];

int solve(vector<int> &v,int k)
{
    for(int i=1;i<=k;i++)
    {
        int j=0;
        int f=1;
        while(v[j]<=i && j<v.size())
        {
            if(dp[i-v[j]]==0){
                dp[i]=1;
                f=0;
                break;
            }
            else
                j++;

        }
        if(f==1)
            dp[i]=0;


    }
    return dp[k];



}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;

    for(int i=0;i<n;i++)
    {

        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    memset(dp,0,sizeof dp);
    int x=solve(v,k);
    if(x==0)
        cout<<"Second";
    if(x==1)
        cout<<"First";

    return 0;
}
