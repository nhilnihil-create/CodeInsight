#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 10000000000099ll
#define mod 1000000007
#define prDouble(x) cout<<fixed<<setprecision(10)<< x
double dp[3001][3001];

double solve(vector<double>& arr, int i, int x)
{
    if(x==0)
        return 1;
    if(i==0)
        return 0;
    if(dp[i][x] > -0.9) return dp[i][x];
    return dp[i][x]= arr[i]*solve(arr, i-1, x-1)+ (1-arr[i])*solve(arr, i-1, x);
}
int main()
{
    FASTIO;
    int n;
    cin>>n;
    vector<double> arr(n+1);
    memset(dp, -1, sizeof dp);
    loop(i, 1, n+1)
        cin>>arr[i];
    prDouble(solve(arr, n, (n+1)/2));
    return 0;
}

