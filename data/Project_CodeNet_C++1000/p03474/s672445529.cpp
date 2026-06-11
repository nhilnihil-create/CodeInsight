#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int a,b;
  string s;
  cin >> a >> b >> s;

  string ans="Yes";
  rep(i,a){
    if(s[i]>='0' && s[i]<='9')continue;
    else {
      ans="No";
      cout << ans << endl;
      return 0;
    }
  }
  
  if(s[a]!='-'){
      ans="No";
      cout << ans << endl;
      return 0;
  }
  
  rep(i,b){
    if(s[a+1+i]>='0' && s[a+1]<='9')continue;
    else {
      ans="No";
      cout << ans << endl;
      return 0;
    }
  }
  
  cout << ans << endl;
}
