#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>=b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<=b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> A(1<<N);
    rep(i,1<<N) cin >> A[i];
    vector<vector<ll>> dp1(1<<N,vector<ll>(N+1)),dp2(1<<N,vector<ll>(N+1));
    rep(i,1<<N) dp1[i][0]=A[i],dp2[i][0]=0;
    rep(j,N){
        rep(i,1<<N){
            dp1[i][j+1]=dp1[i][j],dp2[i][j+1]=dp2[i][j];
            if (i&(1<<j)){
                if (chmax(dp1[i][j+1],dp1[i&~(1<<j)][j])){
                    dp2[i][j+1]=dp1[i][j];
                    chmax(dp2[i][j+1],dp2[i&~(1<<j)][j]);
                }
                else{
                    chmax(dp2[i][j+1],dp1[i&~(1<<j)][j]);
                }
            }
        }
    }
    ll now=0;
    rep2(i,1,1<<N){
        chmax(now,dp1[i][N]+dp2[i][N]);
        cout << now << endl;
    }
}