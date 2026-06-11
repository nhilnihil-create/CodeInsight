#include<bits/stdc++.h>
using namespace std;
using ll = long long;
long double PI= 3.141592653589793238463;
const int N = 1e5+5;
const int MOD = 1e9+7;

ll a[100005];
ll dp[100005][4];
int n;

void D(int x)
{
    for(int i=x;i<n;i++){
        dp[i][0]=(abs(a[i]-a[i-1])+min(dp[i-1][0],dp[i-1][1]) );
        dp[i][1]=(abs(a[i]-a[i-2])+min(dp[i-2][0],dp[i-2][1]) );
    }
}

int main()
{
//int t; cin>>t;

//while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        dp[i][0]=N*N;
        dp[i][1]=N*N;
    }
    dp[0][0]=0;
    dp[1][0]=(abs(a[0]-a[1]));
    D(2);

    cout<<min( dp[n-1][0] , dp[n-1][1] );

//}


    return 0;
}

