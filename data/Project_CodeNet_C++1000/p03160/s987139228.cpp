#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define PB push_back
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
int arr[100005];
int dp[100005];

int f(int indx)
{
    if(indx>=n-1)
        return 0;

    if(dp[indx]!=-1)
        return dp[indx];
    if(indx+1 <=n-1 && indx+2 <=n-1)
           return dp[indx]=min(abs(arr[indx]-arr[indx+1])+f(indx+1), abs( arr[indx]-arr[indx+2])+f(indx+2));
    else if(indx+1 <= n-1)
        return dp[indx]=abs( arr[indx]-arr[indx+1])+f(indx+1);
}

int main()
{
    optimize();
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<f(0)<<endl;
    return 0;
}
