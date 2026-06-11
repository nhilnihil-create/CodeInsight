#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int ans = 0;
  int month1 = s.at(6) - '0';
  int month2 = s.at(5) - '0';
  if (month1 < 5){
    if (month2 == 0)
      ans = 1;
  }
  
  if (ans == 1)
    cout << "Heisei" << endl;
  else
    cout << "TBD" << endl;
}