#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;

int main() {
  string s,t;
  cin>>s>>t;
  ///////
  bool ok=false;
  string ans=s;
  int n=s.size();
  int m=t.size();
  rep(i,n-m+1){
    bool au=true;
    rep(j,m){
  
      if(s[i+j]!='?'&&s[i+j]!=t[j]){
       au=false;
        break;
      }
    }
    
    if(au){
     string kari=s;
      rep(j,m){
        kari[i+j]=t[j] ;
      }
      ans=kari;
      ok=true;
    }
   
    
    
    
  }
  
  
  
  rep(i,n){
   if(ans[i]=='?') ans[i]='a'; 
  }
  
  
  
  
  
  if(ok) cout<<ans<<endl;
  else cout<<"UNRESTORABLE"<<endl;
}