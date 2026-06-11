#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
//typedef pair<ll, ll> P;
const ll INF=1LL<<60;
ll gcd(ll x,ll y){return y? gcd(y,x%y) :x;}

ll dp[200010];
int main(){
    int n,k;
    cin>>n>>k;
    vector<ll>h(n);
    rep(i,200010)dp[i]=INF;
    rep(i,n)cin>>h[i];
    dp[0]=0;
    dp[1]=abs(h[1]-h[0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            if(i-j-1>=0)chmin(dp[i],dp[i-j-1]+abs(h[i]-h[i-j-1]));
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}