#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const int INF = 1000000;
const double PI=3.14159265359;

int main(){

  string s;cin>>s;
  ll n=s.size();
  string k="";
  rep(i,0,n)if(s[i]!='x')k+=s[i];
  bool e=true;
  rep(i,0,(k.size()+1)/2){
    if(k[i]!=k[k.size()-1-i])e=false;
  }

  if(!e){
    out(-1);
    return 0;
  }

  ll ans=0;
  while(s.size()>1){
    if(s[0]==s[s.size()-1]){
      s.pop_back();
      s.erase(s.begin());
    }else{
      ans++;
      if(s[0]=='x'){
        s+='x';
      }else if(s[s.size()-1]=='x'){
        s.insert(s.begin(),'x');
      }else{
        out(-1);
        return 0;
      }
    }
  }
  out(ans);


  return 0;
}
