#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
  string s; cin>>s;
  
  int ct=0, ans=0;
  for(int i=0; i<s.size(); i++){
    if(s[i]=='A' || s[i]=='C' || s[i]=='G' ||s[i]=='T'){
      ct++;
    }else{
      ct=0;
    }
    ans = max(ans,ct);
  }
  cout << ans << endl;
}
