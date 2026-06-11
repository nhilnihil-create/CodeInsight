#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define int long long int
#define endl "\n"
#define pb push_back
int dp[100001][2];
vector<int> v[100001];

void Indset(int n, int p){
    dp[n][0]=1;
    dp[n][1]=1;
    for(auto c : v[n]){
        if(c!=p){
            Indset(c,n);
            dp[n][0]=(dp[n][0]*(dp[c][1]+dp[c][0]))%M;
            dp[n][1]=(dp[n][1]*dp[c][0])%M;
        }
    }
}

int32_t main(){
    int n,x,y;
    cin>>n;
    for(int i=0; i<n-1; i++){
        cin>>x>>y;
        --x, --y;
        v[x].pb(y);
        v[y].pb(x);
    }
    Indset(0,-1);
    cout<<(dp[0][0]+dp[0][1])%M;
    return 0;
}
