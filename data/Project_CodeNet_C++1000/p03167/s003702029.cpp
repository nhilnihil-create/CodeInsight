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
    int n,m;
    cin>>n>>m;
    char mat[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    int dp[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(i+j==0)
                dp[i][j]=1;
            else
                dp[i][j]=0;
            if(mat[i][j]=='#' || i+j==0)
                continue;
            dp[i][j]=0;
            if(i==0)
                dp[i][j]+=dp[i][j-1];
            else if(j==0)
                dp[i][j]+=dp[i-1][j];
            else
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
            dp[i][j]%=mod;

        }
    cout<<dp[n-1][m-1];
    return 0;
}