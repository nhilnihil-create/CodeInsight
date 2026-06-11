#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

int main(){
  string S; cin >> S;
  
  bool OK = true;
  if(S.size() <= 7);
  else{
      int lcount = 0;
      for(int i = 0; i < S.size(); i++){
          if(S.at(i) == 'x') lcount++;
      }
      if(lcount >= 8) OK = false;
  }
  if(OK) cout << "YES" << endl;
  else cout << "NO" << endl;
}

