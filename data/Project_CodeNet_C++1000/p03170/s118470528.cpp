#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 10000000000099ll
#define mod 1000000007
#define prDouble(x) cout<<fixed<<setprecision(10)<<x

int solve(vector<int> arr, int n, int k)
{
    int dp[k+1]= {0};
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(arr[j]>i) continue;
            if(dp[i-arr[j]]==0){
                dp[i]=1;
                break;
            }
        }
    }
    return dp[k];
}

int main()
{
    FASTIO;
    int n,k;
    cin>>n>>k;
    vector<int> arr(n+1);
    loop(i,1, n+1){
        cin>>arr[i];
    }
    solve(arr, n, k)==1 ? cout<<"First" : cout<<"Second";
    return 0;
}


