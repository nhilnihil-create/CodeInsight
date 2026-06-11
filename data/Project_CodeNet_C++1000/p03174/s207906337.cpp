#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    int N;
    cin>>N;
    vector<vector<int>> a(N,vector<int>(N));
    rep(i,N)rep(j,N){
        cin>>a.at(i).at(j);
    }
    ll MX=1;
    rep(i,N)MX*=2;
    vector<vector<ll>> dp(N+1,vector<ll>(MX));
    dp[0][0]=1;
    vector<vector<ll>> flist(N+1,vector<ll>(0));
    rep(i,MX){
        int cnt=0;
        rep(j,N){
            if(i&1ll<<j)cnt++;
        }
        flist.at(cnt).pb(i);
    }
    rep(male,N){
        for(ll S:flist.at(male)){
            rep(female,N){
                if(S & 1ll<<female)continue;
                if(a.at(male).at(female)==0)continue;
                dp[male+1][S|1ll<<female]+=dp[male][S];
                dp[male+1][S|1ll<<female]%=MOD;
            }
        }
    }
    cout<<dp[N][MX-1]<<endl;
}