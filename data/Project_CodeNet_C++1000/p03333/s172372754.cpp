#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end



int main(){
   int n; scanf("%d",&n);
   vector<int> lb(n+1,0),rb(n+1,0);
   rep(i,0,n)scanf("%d%d",&lb[i],&rb[i]);
   sort(ALL(lb)); sort(ALL(rb)); reverse(ALL(lb));
   ll ans=0;
   rep(i,0,n+1)ans+=2*max(0,lb[i]-rb[i]);
   printf("%lld\n",ans);
   return 0;
}