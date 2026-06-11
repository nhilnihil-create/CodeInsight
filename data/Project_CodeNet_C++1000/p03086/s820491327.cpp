#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  int s=0,ans=0;
  
  cin >> S;
  for(int i=0;i<S.size();++i){
    char x = S.at(i);
    if(x == 'A' || x == 'C' || x == 'G' || x == 'T'){
      s+=1;
    }else{
      if(s > ans) ans = s;
      s = 0;
    }
  }
  if(s > ans) ans = s;
  cout << ans << endl;
  return 0;
}
