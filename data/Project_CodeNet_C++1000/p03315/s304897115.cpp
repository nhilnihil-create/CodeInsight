#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans=0;
  
  for(int i=0; i<4; i++) {
    if(S.at(i) == '+') ans++;
    else ans--;
  }
  
  cout << ans << endl;
  
}