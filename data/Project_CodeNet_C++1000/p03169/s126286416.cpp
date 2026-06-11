#include <bits/stdc++.h>
#define MOD  1000000007

using namespace std;
typedef long long int lli;
typedef long double ld;

ld dp[301][301][301];
int n;

lli power(lli a, lli b){
    if(b==0){
        return 1;
    }
    if(b&1){
        return a*power(a*a,b/2);
    }
    return power(a*a,b/2);
}

ld recu(int x, int y, int z){
    //cout<<x<<" "<<y<<" "<<z<<endl;
    if(x<0 || y<0 || z<0){
        return 0;
    }
    if(x+y+z == 0){
        return 0;
    }
    if(dp[x][y][z] > 0){
        return dp[x][y][z];
    }
    ld p0=(x+y+z),p1=x, p2=y, p3=z;
    //cout<<p0<<" "<<p1<<" "<<p2<<" "<<p3<<endl;
    dp[x][y][z]=(n + p1*recu(x-1,y,z) + p2*recu(x+1,y-1,z) + p3*recu(x,y+1,z-1))/(p0);
    //cout<<dp[x][y][z]<<endl;
    return dp[x][y][z];
}

void solve(){
    cin>>n;
    int p[n];
    int ar[4];
    memset(dp, (ld)-1, sizeof(dp));
    memset(ar, 0, sizeof(ar));
    for(int i=0; i<n; i++){
        cin>>p[i];
        ar[p[i]]++;
    }
    //cout<<ar[1]<<" "<<ar[2]<<" "<<ar[3]<<endl;
    ld ans=recu(ar[1], ar[2], ar[3]);
    cout<<setprecision(30)<<ans<<endl;
}

signed main(){
    /*#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
