#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int i;
  i = 0;
  for(int j=0; j<3; j++){
    if(S.at(j) == 'o'){
    i++;
    }
  }
  cout << 700 + i*100 << endl;
}
