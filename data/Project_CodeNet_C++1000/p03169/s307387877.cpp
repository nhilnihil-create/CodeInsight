#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define NUM 1000000009
#define MAX 100001
#define INF LLONG_MAX
double dp[301][301][301];
double solve(ll x, ll y, ll z,ll &n){
    if(x<0 || y<0 || z<0)
        return 0.0;
    if(x==0 && y==0 && z==0)
        return 0.0;
    if(dp[x][y][z]>0.0)
        return dp[x][y][z];
    ll eval = x+y+z;
    double ans = 1.0*n+1.0*x*solve(x-1,y,z,n)+1.0*y*solve(x+1,y-1,z,n)+1.0*z*solve(x,y+1,z-1,n);
    return dp[x][y][z]=1.0*ans/eval;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,tmp;
    cin>>n;
    ll one=0,two=0,three=0;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp==1)
            one++;
        else if(tmp==2)
            two++;
        else if(tmp==3)
            three++;
    }
    memset(dp,-0.9,sizeof(dp));
    cout<<fixed<<setprecision(9)<<solve(one,two,three,n)<<endl;
    return 0;
}
