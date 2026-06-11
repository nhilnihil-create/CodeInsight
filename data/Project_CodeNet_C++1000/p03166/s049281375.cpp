#include<bits/stdc++.h>
#define ll          long long int
#define ld          long double
#define pb          push_back
#define mp          make_pair
#define ff          first
#define se          second
#define scan(n)     scanf("%lld", &n);
#define print(n)    printf("%lld\n", n);
#define fd(n)       fixed<<setprecision(n)
#define MAX         1000000000000000000
#define MAXN        100005
#define LOG         19
#define mod         1000000007
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,i,x,y,mx=0;
    cin>>n>>m;
    vector<ll> vi[n+1];
    ll deg[n+1];
    queue<ll> qe;
    vector<ll> vi1;
    memset(deg,0,sizeof(deg));
    for(i=1;i<=m;i++){
        cin>>x>>y;
        vi[x].pb(y);
        deg[y]++;
    }
    for(i=1;i<=n;i++){
        if(deg[i]==0){
            qe.push(i);
            vi1.pb(i);
        }
    }
    while(!qe.empty()){
        ll node=qe.front();
        qe.pop();
        for(auto x:vi[node]){
            deg[x]--;
            if(deg[x]==0){
                vi1.pb(x);
                qe.push(x);
            }
        }
    }
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    for(auto node:vi1){
        for(auto x:vi[node]){
            dp[x]=max(dp[x],dp[node]+1);
        }
    }
    for(i=1;i<=n;i++){
        mx=max(mx,dp[i]);
    }
    cout<<mx;
}