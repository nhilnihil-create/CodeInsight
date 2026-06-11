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

ll dp[20010]={};

int main(){
    int n; scanf("%d",&n);
    vector<int> w(n),s(n),v(n),ord(n);
    rep(i,0,n)scanf("%d%d%d",&w[i],&s[i],&v[i]);
    iota(ALL(ord),0);
    sort(ALL(ord),[&](int i,int j){return s[i]+w[i]<s[j]+w[j];});
    for(int i:ord)rrep(j,s[i],-1){
        chmax(dp[j+w[i]],dp[j]+v[i]);
    }
    ll ans=0;
    rep(i,0,20010)chmax(ans,dp[i]);
    printf("%lld\n",ans);
    return 0;
}