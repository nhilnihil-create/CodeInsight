#include <bits/stdc++.h>
using namespace std;

int main() {

  string s;
  long long k;
  cin >> s >> k;
  
  int size = s.size();
  
  //cout << size << endl;
  
  int hantei1 = 1, cnt = 0, num = -1;
  
  for ( int i = 0; i < size; i++){
    if ( s[i] != '1' ){
      hantei1 = 0;
      cnt = i;
      num = s[i] - '0';
      //cout << hantei1 << ' ' << cnt << ' ' << num << endl;
      break;
    }
  }
  
  if ( hantei1 == 1 ){
    cout << 1 << endl;
    return 0;
  }
  
  if ( cnt >=  k ){
    cout << 1 << endl;
  }else{
    cout << num << endl;
  }
  
  return 0;

}