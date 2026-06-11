#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
int main(){
  string s;
  cin >> s;
  string t="ATGC";
  int ans=0,sum=0;
  rep(i,s.size()){
    bool is=false;
    rep(j,4){
      if(s.at(i)==t.at(j)){
        is=true;
      }
    }
    if(is){
      sum++;
    }else{
      sum=0;
    }
    ans=max(ans,sum);
  }
  cout << ans;
}
      
    
      