#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
const ll INF = 1LL<<60;
const ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,q;cin>>n>>m>>q;
    vector<vector<ll>> lr = vector<vector<ll>>(n,vector<ll>(n,0));
    vector<vector<ll>> dp = vector<vector<ll>>(n,vector<ll>(n,0));
    rep(i,m){
        ll l,r;cin>>l>>r;
        l--;r--;
        lr[l][r]++;
    }
    rep(i,n){
        rep2(j,i,n){
            if(i==j)dp[i][j]=lr[i][j];
            else{
                dp[i][j]=dp[i][j-1];
                rep2(k,i,j+1){
                    dp[i][j]+=lr[k][j];//累積和使ったほうがよさげ
                }
            }
        }
    }
    rep(i,q){
        ll p,q;cin>>p>>q;
        cout<<dp[p-1][q-1]<<endl;
    }
    return 0;
}