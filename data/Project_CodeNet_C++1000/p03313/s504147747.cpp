#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
string to_str(ll x){string res; while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return res;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end

typedef pair<ll,ll> P;
void p_max(P& a,P b){
   if(a.first<b.first){a.second=max(a.first,b.second); a.first=b.first;}
   else chmax(a.second,b.first);
}

int main(){
   int n; scanf("%d",&n);
   vector<P> dp(1<<n);
   rep(i,0,1<<n){
      int tmp; scanf("%d",&tmp);
      dp[i]={tmp,-INF};
   }
   rep(i,0,n)rep(mask,0,1<<n)if(mask>>i&1){
      p_max(dp[mask],dp[mask&~(1<<i)]);
   }
   ll res=-INF;
   rep(mask,0,1<<n){
      chmax(res,dp[mask].first+dp[mask].second);
      if(mask)printf("%lld\n",res);
   }
   return 0;
}