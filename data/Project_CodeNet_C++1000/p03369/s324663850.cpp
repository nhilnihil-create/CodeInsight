#include <bits/stdc++.h>
using namespace std;
main(){
  string S;
  int y = 700;
  cin >> S;
  if(S[0] == 'o') y += 100;
  if(S[1] == 'o') y += 100;
  if(S[2] == 'o') y += 100;
  cout << y << endl;
}