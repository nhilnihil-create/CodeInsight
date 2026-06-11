#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repn(i,n) for(ll i=0;i<=(ll)(n);i++)
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
//cin.tie(0);
//ios::sync_with_stdio(false);

ll dp[2010][2]={};//iより先からとれる

signed main(){
    ll n,x,y;cin>>n>>x>>y;

    vector<ll> a(n);
    rep(i,n)cin>>a[i];

    if(1<n){
        dp[n][0]=abs(a[n-1]-a[n-2]);
        dp[n][1]=abs(a[n-1]-a[n-2]);
    }else{
        cout<<abs(y-a[0])<<endl;
        return 0;
    }

    for(int i=n-1;0<=i;i--)
    {
        for(int j=i+1;j <= n;j++)
        {   
            if(0<i)dp[i][0]=max(dp[j][1],abs(a[i-1]-a[n-1]));
            else dp[i][0]=max(dp[j][1],abs(y-a[n-1]));
        }

        for(int j=i+1;j <= n;j++)
        {
            dp[i][1]=INF;
            if(0<i)dp[i][1]=min(dp[j][0],abs(a[i-1]-a[n-1]));
            else dp[i][1]=min(dp[j][0],abs(x-a[n-1]));
        }
        //cout<<dp[i][0]<<":"<<dp[i][1]<<endl;
    }

    cout<<dp[0][0]<<endl;
}