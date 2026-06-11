#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S,T;
  cin >> S >> T;
  string t;
  
  for (int i = 0; i < S.size(); i++) {
    char C = T.at(0);
    T = T + C;
    t = T.at(1);
    for (int j = 1; j < S.size(); j++) {
      t += T.at(j+1);
    }
    T = t;
    if (S == T){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}

