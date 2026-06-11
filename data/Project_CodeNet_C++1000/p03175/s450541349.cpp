#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod =1000000007;

unordered_map<int,list<int>> m;
ll dp[100010][2];

ll fun(int par,int src,int c){
    if(m.count(src)==0){
        if(c==0)return 2;
        else return 1;
    }
    if(dp[src][c]>-1)return dp[src][c];
    ll w=1,b=1;
    for(int i:m[src]){
        if(i==par)continue;
        w*=fun(src,i,0);
        w%=mod;
        if(c==0){
            b*=fun(src,i,1);
            b%=mod;
        }
    }
    if(c==0){
        return dp[src][c]=(w+b)%mod;
    }
    else{
        return dp[src][c]=w;
    }
}
void solve()
{
    int n;
    cin>>n;
    if(n==1){
        cout<<2;
        return;
    }
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        m[x].push_back(y);
        m[y].push_back(x);
    }
    memset(dp,-1,sizeof dp);
    fun(-1,1,0);
    cout<<dp[1][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
