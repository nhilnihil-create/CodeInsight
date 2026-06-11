#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
  string s;
  cin >> s;
  
  int n = s.size();
  bool ok = false;
  if(s[0] == 'A'){
    int c = s.find("C");
    if(c>=2 && c<n-1){
      ok = true;
      rep(i,n){
        if(!i) continue;
        if(i==c) continue;
        if(s[i]<'a' || s[i]>'z') ok = false;
      }
    }
  }
  cout << ( ok ? "AC" : "WA" ) << endl;
  return 0;
}