#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int n=S.size();
  
  string ans="No"; 
  for(int i=0; i<n; i++){
    if(S==T)ans="Yes";
    S=S+S.at(0);
    S.erase(0,1);
  }
  
  cout << ans << endl;
}