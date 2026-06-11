#include <bits/stdc++.h>
using namespace std;

int main() {
  int n[4];
  char s[4];

  cin >> s;
  for(int i = 0; i < 4; i++){
    n[i] = s[i] - '0';
  }

  char op[3];
  for(int bit = 0; bit < (1<<3); bit++){
    int tot = n[0];
    for(int i = 0; i < 3; i++){
      if(bit & (1 << i)){
        op[i] = '+';
        tot += n[i+1];
      }
      else{
        op[i] = '-';
        tot -= n[i+1];
      }
    }

    if(tot == 7){
      cout << n[0];
      for(int i = 0; i < 3; i++){
        cout << op[i];
        cout << n[i+1];
      }
      cout << "=7" << endl;

      break;
    }
  }

  return 0;
}