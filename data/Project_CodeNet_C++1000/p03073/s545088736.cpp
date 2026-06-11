#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int counta = 0;
  int countb = 0;

  vector<char> C(S.size());
  for (int i = 0; i < S.size(); i++) {
    C.at(i) = S.at(i);

    if (i % 2 == 0 && C.at(i) == '1'){
      counta++;
    }
    else if (i % 2 == 1 && C.at(i) == '0'){
      counta++;
    }
    else if (i % 2 == 1 && C.at(i) == '1'){
      countb++;
    }
    else if (i % 2 == 0 && C.at(i) == '0'){
      countb++;
    }
  }
 
  if (counta > countb){
    cout << countb << endl;
  }
  else {
    cout << counta << endl;
  }
}
    
  