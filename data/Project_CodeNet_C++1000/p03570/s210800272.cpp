#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end

int dp[200010],mask[200010],mi[1<<26];

int main(){
    string s; cin>>s; int n=s.size();
    rep(i,0,n+1)dp[i]=inf; dp[0]=0;
    rep(i,0,n)mask[i+1]=mask[i]^(1<<(s[i]-'a'));
    rep(i,0,1<<26)mi[i]=inf; mi[0]=0;
    rep(i,0,n){
        chmin(dp[i+1],mi[mask[i+1]]+1);
        rep(j,0,26)chmin(dp[i+1],mi[mask[i+1]^(1<<j)]+1);
        chmin(mi[mask[i+1]],dp[i+1]);
    }
    printf("%d\n",dp[n]);
    return 0;
}