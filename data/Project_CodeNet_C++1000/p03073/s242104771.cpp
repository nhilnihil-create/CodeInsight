#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans = 0;
  string s ;
  cin >> s ;
  int ss = s.size();
  
  for(int i=0;i<ss-1;i++){
    if(s[i]=='0'&&s[i+1]=='0'){
      ans++;
      s[i+1] = '1';
    }
    if(s[i]=='1'&&s[i+1]=='1'){
      ans++;
      s[i+1]='0';
    }
  }
  
  cout << ans << endl;
}
      
