#include <bits/stdc++.h>
using namespace std;

int main () {
  string a;
  cin >> a;
  
  string s;
  int ans=0;
  
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    s=a[0];
    ans +=a[0]-'0';
    
    for (int i = 0; i < 3; i++) {
      if (tmp & (1<<i)) {
        s+='+';
        s+=a[i+1];
        ans += a[i+1]-'0';        
      }else{
        s+='-';
        s+=a[i+1];
        ans -= a[i+1]-'0';  
      }
    }
    if(ans==7){
      break;
    }
    ans=0;
  }
  cout << s << "=7"<< endl;
  return 0;
}