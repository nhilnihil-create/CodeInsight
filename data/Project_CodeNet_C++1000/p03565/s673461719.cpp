#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  string s,t;
  cin >> s >> t;

  int n = s.size();
  int m = t.size();
  bool ok=true;
  
  rep(i,n-m+1){
    ok = true;
    int k = n-m-i;
    rep(j,m){
      if(s.at(k+j)!=t.at(j)){ok = false; break;}
    }
    if(ok){
      rep(j,m){
        s.at(k+j) = t.at(j);
      }
      break;
    }
  }

  if(!ok){
    rep(i,n-m+1){
      ok = true;
      int k = n-m-i;
      rep(j,m){
        if(s.at(k+j)!=t.at(j)&&s.at(k+j)!='?'){ok = false; break;}
      }
      if(ok){
        rep(j,m){
          s.at(k+j) = t.at(j);
        }
        break;
      }
    }
  }
  
  rep(i,n){
    if(s.at(i)=='?') s.at(i)='a';
  }

  if(!ok||m>n) cout << "UNRESTORABLE";
  else cout << s;
}

