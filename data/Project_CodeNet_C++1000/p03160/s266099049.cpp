#include<bits/stdc++.h>
using namespace std;
using ll = long long;
long double PI= 3.141592653589793238463;
const int N = 1e5+5;
const int MOD = 1e9+7;

ll a[100005];
ll dp[100005];
int n,k;

void D(int x)
{
    for(int i=x;i<n;i++){
        for(int j=1;j<=2;j++){
            dp[i]=min(abs(a[i]-a[i-j])+dp[i-j],dp[i]);
        }
    }
}

int main()
{
//int t; cin>>t;

//while(t--){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        dp[i]=N*N;
    }
    dp[0]=0;
    dp[1]=(abs(a[0]-a[1]));
    D(2);
//for(int i=0;i<n;i++) {
//        cout<<dp[i]<<' ';
//    }
    cout<<dp[n-1];

//}


    return 0;
}

