//https://codeforces.com/blog/entry/64250?fbclid=IwAR2gUYNv6XP1qDbhkwuc_nVXFNxQ8fQrZ53dZHFCTomNUvINIBv9LIpbWCQ#comment-482534

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define fWrite          freopen ("out.txt","w",stdout);
#define TC              int t;cin >> t;FOR(tc,1,t)
#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

#define Make(x,p)       (x | (1<<p))
#define DeMake(x,p)     (x & ~(1<<p))
#define Check(x,p)      (x & (1<<p))
#define popcount(x)     __builtin_popcount(x)

const LL MOD=1e9+7;
const int N=3003;
LL dp[2][N];

int main(){
    int n;
    string s;
    cin >> n >> s;
    FOR(i,1,n) dp[0][i]+=dp[0][i-1]+1; //I really don't get it
    int now=0;
    FOR(i,1,n-1){
        now=1-now;
        if(s[i-1]=='>') {
            FOR(j,1,i+1) {
                dp[now][j]=(dp[now][j-1]+dp[1-now][i]-dp[1-now][j-1])%MOD;
            }
        }
        else{
            FOR(j,1,i+1){
                dp[now][j]=(dp[now][j-1]+dp[1-now][j-1])%MOD;
            }
        }
    }
    LL ans=(dp[now][n]+MOD)%MOD;
    cout << ans;
}
