#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int yymm = 0, mmyy = 0;
  if (s.at(0) == '0'){
    if (s.at(1) != '0')
      mmyy = 1;
  }
  else if (s.at(0) == '1'){
    if (s.at(1) == '1' || s.at(1) == '2')
      mmyy = 1;
  }
  
  if (s.at(2) == '0'){
    if (s.at(3) != '0')
      yymm = 1;
  }
  else if (s.at(2) == '1'){
    if (s.at(3) == '1' || s.at(3) == '2')
      yymm = 1;
  }
  
  if (yymm == 1 && mmyy == 1)
    cout << "AMBIGUOUS" << endl;
  else if (yymm == 1 && mmyy == 0)
    cout << "YYMM" << endl;
  else if (yymm == 0 && mmyy == 1)
    cout << "MMYY" << endl;
  else
    cout << "NA" << endl;
}