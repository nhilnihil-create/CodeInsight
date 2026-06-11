#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<l_l> vpl;
typedef vector<string> vs;
typedef pair<l_l,ll> lll;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=1;i<=(n);i++)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=10100100100100100;
const ll dx[4]={1,-1,0,0};
const ll dy[4]={0,0,1,-1};
template<class T> inline bool chmin(T& a,T b){
if(a>b){
a=b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a,T b){
if(a<b){
a=b;
return true;
}
return false;
}
ll n;
ll a[20][20];
ll dp[1<<16];
ll cost[1<<16];
int main(){
    cin>>n;
    rep(i,n)rep(j,n)cin>>a[i][j];
    for(int Q=1;Q<(1<<n);Q++){
        rep(i,n){
            if(Q>>i&1){
                for(int j=i+1;j<n;j++){
                    if(Q>>j&1){
                        cost[Q]+=a[i][j];
                    }
                }
            }
        }
    }
    for(int Q1=1;Q1<(1<<n);Q1++){
        for(int Q2=Q1;Q2>0;Q2=(Q2-1)&Q1){
            dp[Q1]=max(dp[Q1],dp[Q1-Q2]+cost[Q2]);
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}