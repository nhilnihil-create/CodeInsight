#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define big 998244353
#define ff first
#define se second
#define pb push_back
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define PSET(x,y) fixed<<setprecision(y)<<x
#define mp make_pair
#define pi 3.141592653589
int power(int x,int y){
    int r=1,z=x;
    while(y){
        if(y & 1)r*=z;
        z*=z;y=y>>1;}
    return r;}
int powerm(int x,int y,int p){
    int r=1;
    while(y){
        if(y & 1)r=(r*x)%p;
        y=y>>1;
        x=(x*x)%p;}
    return r%p;}
int modinv(int x,int m){
    return powerm(x,m-2,m);}
int logarithm(int a,int b){
    int x=0;
    while(a>1){
        x++;
        a/=b;}
    return x;}
int32_t main(){
    fast;
    int n;
    cin>>n;
    double dp[n+1][n+1];
    dp[0][0]=1.0;
    for(int i=1;i<=n;i++){
        double p;
        cin>>p;
        for(int j=0;j<=i+1;j++)
            dp[i][j]=0.0;
        for(int j=0;j<=i;j++){
            dp[i][j]+=dp[i-1][j]*(1-p);
            dp[i][j+1]+=dp[i-1][j]*p;
        }
    }
    double ans=0.0;
    for(int i=n/2+1;i<=n;i++)
        ans+=dp[n][i];
    printf("%.10f",ans);
    return 0;
}