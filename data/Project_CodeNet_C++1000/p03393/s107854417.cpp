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

  if(s.size()==26){
    map<char,bool>mp;
    rep(i,0,s.size())mp[s[i]]=true;
    for(int i=s.size()-1;i>=0;i--){
      mp[s[i]]=false;
      rep(j,s[i]-'a'+1,26){
        if(!mp['a'+j]){
          out(s.substr(0,i)+char('a'+j));
          return 0;
        }
      }
    }
    out(-1);
  }
  else{
    rep(i,0,26){
      if(s.find('a'+i)==string::npos){
        out(s+char('a'+i));
        return 0;
      }
    }
  }


  return 0;
}
