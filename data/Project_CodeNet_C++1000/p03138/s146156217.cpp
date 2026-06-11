#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

int main(){
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> A(N,0);
    for(ll i=0;i<N;i++)cin>>A[i];
    vector<ll> count(41,0);
    for(ll i=0;i<41;i++)
        for(ll j=0;j<N;j++){
            if(A[j]&(1LL<<i))count[i]++;
        }
    //dp[i][j]のiは未満フラグ、j桁目までみたときの最大値
    vector<vector<ll>> dp(2, vector<ll>(42, 0));

    ll ok=0;

    for(ll i=40;i>=0;i--){
        if(ok==1)ok=2;
        if(!ok&&(K&(1LL<<i)))ok=1;
        if(ok==2&&(K&(1LL<<i))){
            //未満なら０，１
            chmax(dp[1][i],dp[1][i+1]+max(N-count[i],count[i])*(1LL<<i));
            //一致から０
            chmax(dp[1][i],dp[0][i+1]+count[i]*(1LL<<i));
            //一致から1
            chmax(dp[0][i],dp[0][i+1]+(N-count[i])*(1LL<<i));
        }
        else if(ok==1&&(K&(1LL<<i))){
            //一致から０
            chmax(dp[1][i],dp[0][i+1]+count[i]*(1LL<<i));
            //一致から1
            chmax(dp[0][i],dp[0][i+1]+(N-count[i])*(1LL<<i));
        }
        else{
            //Kが始まっていれば未満から０，１
            if(ok)chmax(dp[1][i],dp[1][i+1]+max(N-count[i],count[i])*(1LL<<i));
            //一致から0
            chmax(dp[0][i],dp[0][i+1]+(count[i])*(1LL<<i));
        }
    }

    print(max(dp[0][0],dp[1][0]))

    return 0;
}
