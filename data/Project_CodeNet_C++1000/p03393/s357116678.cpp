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
   string s; cin>>s;
   if(s.size()!=26){
      rep(i,0,26)if(!count(ALL(s),(char)('a'+i))){
         s+=(char)('a'+i); cout<<s<<endl; return 0;
      }
   }
   else{
      string t=s;
      if(!next_permutation(ALL(s))){puts("-1"); return 0;}
      rep(i,0,s.size()){
         cout<<s[i];
         if(s[i]!=t[i])return 0;
      }
   }
   return 0;
}