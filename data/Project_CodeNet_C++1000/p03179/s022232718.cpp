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

ll N;
string S;

vector<vector<ll>> dp(3010, vector<ll>(3010, -1));
//後ろx個がまだ決めてない、かつ末尾がy番目に入る
ll F(ll x,ll y){
    if(dp[x][y]!=-1)return dp[x][y];
    if(x==0)return dp[x][y]=1;
    if(x==N){
        ll ans=0;
        for(ll i=1;i<=N;i++)ans+=F(N-1,i);
        return dp[x][y]=ans%MOD;
    }
    ll ret=0;
    if(S[N-x-1]=='<'){
        if(y<x)ret+=F(x-1,y)+F(x,y+1);
        else if(y==x)ret+=F(x-1,x);
    }
    else {
        if(y>=3)ret+=F(x,y-1)+F(x-1,y-1);
        else if(y==2)ret+=F(x-1,1);
    }
    return dp[x][y]=ret%MOD;
}


int main(){
    cin >> N;
    cin >> S;
    
    print(F(N,0))

    return 0;
}
