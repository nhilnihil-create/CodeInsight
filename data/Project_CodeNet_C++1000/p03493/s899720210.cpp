#include <bits/stdc++.h>
using namespace std;

int main() {
  int s[3] = {};
  string str;
  cin >> str;
  
  int ans = 0;
  for( int i = 0; i < 3; ++i){
    s[i] = str[i]-'0';
    
    if( s[i] == 1 ){
      ++ans;
    }
  }
  
  cout << ans << endl;
}