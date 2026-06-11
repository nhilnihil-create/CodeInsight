#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<ll> a(n),sm(n+1);
    REP(i,n){
        cin >> a[i];
        sm[i+1]+=sm[i]+a[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    REP(i,n-1){
        dp[i][i+2]=sm[i+2]-sm[i];
    }
    FOR(i,2,n+1){
        for(int j=0;j+i<=n;j++){
            ll tmp=INF;
            for(int k=j+1;k<j+i;k++){
                chmin(tmp,dp[j][k]+dp[k][j+i]+sm[j+i]-sm[j]);
            }
            dp[j][j+i]=tmp;
        }
    }
    cout << dp[0][n] << endl;
}