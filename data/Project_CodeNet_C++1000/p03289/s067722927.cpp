#include <bits/stdc++.h>
using namespace std;


int main() {
  string S; cin >> S;
  bool C_exist = false;
  int C = 0;
  if(S[0] == 'A'){
    for(int i = 1; i < (int)S.size(); i++){
      if(S[i] == 'C'){
        C_exist = true;
        C++;
      }
      if(C > 1 ||(S[i] != 'C' && S[i] < 'a')){
        C_exist = false;
        break;
      }
    }
    if(S[1] == 'C' || S[(int)S.size()-1] == 'C') C_exist = false;
  }
  if(C_exist) cout << "AC" << endl;
  else cout << "WA" << endl;
}
