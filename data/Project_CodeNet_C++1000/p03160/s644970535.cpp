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
    vector<int> h(n),dp(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(int i=0;i<n;i++){
        if(i+1<n)
            dp[i+1]=min(dp[i+1],dp[i]+abs(h[i+1]-h[i]));
        if(i+2<n)
            dp[i+2]=min(dp[i+2],dp[i]+abs(h[i+2]-h[i]));
    }
    cout<<dp[n-1];
    return 0;
}