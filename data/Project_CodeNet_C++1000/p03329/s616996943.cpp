#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;
const int maxn = 100100;


int main(void){
    int n;
    cin >> n;
    ll dp[n];
    REP(i,n+1) dp[i]=INF;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        chmin(dp[i],dp[i-1]+1);
        for(int j=6;j<=i;j*=6){
            chmin(dp[i],dp[i-j]+1);
        }
        for(int j=9;j<=i;j*=9){
            chmin(dp[i],dp[i-j]+1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}