#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};


int main() {
    ll N;
    cin >>N;
    vector<ll>mo;
    mo.pb(1);
    ll now6=1;
    while(1){
        now6*=6;
        if(now6>N){
            break;
        }
        mo.pb(now6);

    }

    ll now9=1;
    while(1){
        now9*=9;
        if(now9>N){
            break;
        }
        mo.pb(now9);

    }
    ll M=mo.size();
    vector<vector<ll>>dp(M+1,vector<ll>(N+1,INF));
    dp[0][0]=0;
    rep(i,M){
        dp[i+1][0]=0;
    }
    rep(i,M){
        rep(j,N+1){
            if(j-mo[i]>=0){
                dp[i+1][j] = min({dp[i][j],dp[i][j-mo[i]]+1,dp[i+1][j-mo[i]]+1});
            }else{
                dp[i+1][j]=dp[i][j];
            }
            
        }
    }

    /*rep(i,M+1){
        rep(j,N+1){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout << dp[M][N] << endl;


    return 0;
    

}