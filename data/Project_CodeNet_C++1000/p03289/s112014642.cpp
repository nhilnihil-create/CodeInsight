#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n=s.size();
  int cnt=0;
  for(int i=0; i<n; i++){
    if(i==0){
      if(s[i]!='A'){
        cout << "WA" << endl;
        return 0;
      }
    }
    if('A' <= s[i] && s[i] <= 'Z' && (!(i==0)) && s[i]!='C'){
      cout << "WA" << endl;
      return 0;
    }
    if(i==1) continue;
    if(2<=i && i<=n-2){
      if(s[i]=='C') cnt++;
    }
  }
  if(cnt!=1) cout << "WA" << endl;
  else cout << "AC" << endl;
}
