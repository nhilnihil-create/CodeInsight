#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;

int dp[N][3];

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int T,i,j;
    int n;

    cin>>n;
    int a[n+1];
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[2][0]=a[1];

    for(i=3;i<=n;i++){
        dp[i][0]=gcd(dp[i-1][0],a[i-1]);
    }

    dp[n-1][1]=a[n];

    for(i=n-2;i>=1;i--){
        dp[i][1]=gcd(dp[i+1][1],a[i+1]);
    }
    int g=max(dp[1][1],dp[n][0]);

    for(i=2;i<n;i++){
        int g_=gcd(dp[i][0],dp[i][1]);
        if(g_>g) g=g_;
    }

    printf("%d\n",g);




return 0;
}
