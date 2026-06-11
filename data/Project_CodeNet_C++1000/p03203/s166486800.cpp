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
//end



int main(){
   int h,w,n; scanf("%d%d%d",&h,&w,&n);
   vector<int> x(n),y(n);
   map<int,vector<int>> mp;
   rep(i,0,n){
      scanf("%d%d",&x[i],&y[i]); x[i]--; y[i]--;
      x[i]-=y[i];
      if(x[i]>=0&&y[i]>=0)mp[y[i]].push_back(x[i]);
   }
   int res=h,lb=0;
   for(auto& p:mp){
      vector<int> v=p.second;
      sort(ALL(v));
      for(int pos:v){
         if(lb<=pos-1)chmin(res,pos+p.first);
         if(lb==pos)lb=pos+1;
      }
   }
   printf("%d\n",res);
   return 0;
}