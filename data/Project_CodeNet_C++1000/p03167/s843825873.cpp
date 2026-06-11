#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
#define MOD 1000000007
using namespace std;

int solution(){
    ll h,w; cin>>h>>w;
    vector<vector<char> > a(h, vector<char> (w) );
    for(ll i = 0;i < h;i++)
        for(ll j = 0;j < w;j++)
            cin>>a[i][j];
    
    vector<vector<ll> > dp(h, vector<ll> (w, 0) );
    dp[0][0] = 0;
    for(ll i = 1;i < h;i++){
        if(a[i][0] == '#') break;
        else dp[i][0] = 1;
    }
    for(ll i = 1;i < w;i++){
        if(a[0][i] == '#') break;
        else dp[0][i] = 1;
    }
    for(ll i = 1;i < h;i++){
        for(ll j = 1;j < w;j++){
            if(a[i][j] == '.')
                dp[i][j] = (dp[i-1][j]+dp[i][j-1]) % MOD;
        }
    }
    cout<<dp[h-1][w-1]<<"\n";
    return 0;
}

int main(){
    FAST_IO;
    int T = 1; //cin>>T;
    while(T--)
        solution();
    return 0;
}