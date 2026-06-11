#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  vector<int> v(4);
  for(int i = 0; i < 4; i++)v[i] = s[i] - '0';

  for(int j = 0; j < (1 << 3); j++){
    int tmp = v[0];
    for(int k = 0; k < 3; k++){
      if(j & (1 << k)) tmp += v[k+1];
      else tmp -= v[k+1];
    }
    if(tmp == 7){
      cout << v[0];
      for(int k = 0; k < 3; k++){
        if(j & (1 << k)) cout << '+';
        else cout << '-';
        cout << v[k+1];
      }
      cout << "=7" << endl;
      return 0;
    }
  }
}