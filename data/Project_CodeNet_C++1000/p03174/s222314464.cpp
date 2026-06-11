#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
#define point complex<long long>
#define pi acos(-1)
#define pb push_back


typedef long long ll;

using namespace std;

void Fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, arr[25][25];
int dp[(1<<22)];
int vis;
ll solve(int i){
    if(i==n)
        return 1;
    if(dp[vis]!=-1)
        return dp[vis];
    ll res=0;
    for(int y=0; y<n; y++){
        if((vis>>y)%2==0 && arr[i][y]){
            vis+=(1<<y);
            res+=solve(i+1);
            vis-=(1<<y); res%=mod;
        }
    }
    return dp[vis]=res;
}
int main()
{
    Fastio();
    int ttt=1; //cin>>ttt;
    while(ttt--){
        cin>>n;
        for(int i=0; i<n; i++){
            for(int y=0; y<n; y++){cin>>arr[i][y];}
        }
        memset(dp, -1, sizeof dp);
        cout<<solve(0)<<'\n';
    }

    return 0;
}
