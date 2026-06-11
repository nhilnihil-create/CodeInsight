#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define nl printf("\n")
#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define yes printf("yes\n")
#define NO printf("NO\n")
#define No printf("No\n")
#define no printf("no\n")
using namespace std;
int main(){
    int n;scn(n);
    int h[n+1],dp[n+1];
    for(int i=1;i<=n;i++) scn(h[i]);
    dp[n]=0;
    dp[n-1]=abs(h[n-1]-h[n]);
    for(int i=n-2;i>0;i--){
        dp[i]=min(dp[i+1]+abs(h[i]-h[i+1]),dp[i+2]+abs(h[i]-h[i+2]));
    }
    printf("%d\n",dp[1]);
}
