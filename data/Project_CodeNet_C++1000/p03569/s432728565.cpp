#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int ans = 0;
  int l = 0, r = s.size()-1;
  while(1){
    if(l >= r) break;
    
    char lc = s.at(l), rc = s.at(r);
    if(lc == rc){
      l++, r--;
      continue;
    }
    else if(lc == 'x') l++;
    else if(rc == 'x') r--;
    else{
      ans = -1;
      break;
    }
    
    ans++;
  }
  
  cout << ans << endl;  
}