#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  if (S.size()==2) {
    cout << S <<endl;
  }
  else {
    cout << char(S.at(2)) << char(S.at(1)) << char(S.at(0)) << endl;
  }
}