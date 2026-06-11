#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;  cin >> s;
  int ans = 0, slen = s.size(), p = 0;
  
  while(p < slen){
    int i;
    for(i=p; i<slen; i++){
      bool flag = true;
      for(int j=0; j<4; j++)
        if(s[i] == "ACGT"[j])  flag = false;
      if(flag)  break;
    }
    ans = max(ans, i-p);
    p++;
  }
  
  cout << ans << endl;
  return 0;
}
