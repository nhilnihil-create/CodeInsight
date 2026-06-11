#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string s;
  cin >> s;
  
  int cnt0 = 0,cnt1 = 0,n = s.size();
  
  for ( int i = 0; i < n; i++){
    if ( s[i] == '0' ){
      cnt0++;
    }else if ( s[i] == '1' ){
      cnt1++;
    }
  }
  
  if ( n == 1 || n == cnt0 || n == cnt1 ){
    cout << 0 << endl;
  }else{
    cout << min(cnt0,cnt1) * 2 << endl;
  }
  
}
