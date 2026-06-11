#include<bits/stdc++.h>
#define pi pair<int,int>
#define mk make_pair
#define f(i,n) for(int i=0;i<n;i++)
#define fo(i,a,n) for(int i=a;i<n;i++)
#define fr(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define N 1000000007
using namespace std;

double pro[3005];
vector<vector<double>> dp(3005,vector<double> (1510,-1));
int n;

double total(int ind,int tail)
{
    if(ind>n)
        return 1;
    if(dp[ind][tail]==-1)
    {
        if(tail>0)
        {
            double left=total(ind+1,tail-1)*(1-pro[ind]);
            double right=total(ind+1,tail)*pro[ind];
            dp[ind][tail]=left+right;
        }
        else
            dp[ind][tail]=total(ind+1,tail)*pro[ind];
    }
    return dp[ind][tail];
}

int main()
{
   // int n;
    cin>>n;
    fo(i,1,n+1)
        cin>>pro[i];
    int tail =n/2;
    double ans=total(1,tail);
    printf("%.10f",ans);

}
