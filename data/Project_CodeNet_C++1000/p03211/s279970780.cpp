#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int ss = S.size();
  
  int ans = 1000;
  for(int i=0;i<=ss-3;i++){
    int atai=0;
    atai = (S.at(i)-'0')*100 + (S.at(i+1)-'0')*10 + (S.at(i+2)-'0')*1 ;
    
    int sa = abs (753-atai);
    
    ans = min(ans,sa);
  }
  
  cout << ans << endl;
    
}