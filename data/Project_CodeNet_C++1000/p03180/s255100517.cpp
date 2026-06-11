#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef pair<l_l,ll> lll;
typedef vector<string> vs;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
ll dp[1<<16];
ll cost[1<<16];
ll n;
ll a[16][16];
int main(){
    cin>>n;
    rep(i,n){
        rep(j,n){
            cin>>a[i][j];
        }
    }
    for(int s=1;s<1<<n;s++){
        rep(i,n){
            if(s>>i&1){
                for(int j=i+1;j<n;j++){
                    if(s>>j&1){
                        cost[s]+=a[i][j];
                    }
                }
            }
        }
    }
    dp[0]=0;
    for(int s=1;s<1<<n;s++){
        for(int t=s;t>0;t=(t-1)&s){
            dp[s]=max(dp[s],dp[s-t]+cost[t]);
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}