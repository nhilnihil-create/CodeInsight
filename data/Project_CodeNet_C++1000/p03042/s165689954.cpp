#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  string a = s.substr(0,2);
  string b = s.substr(2,2);
  if(a < "13" && a > "00" && b < "13" && b > "00"){
    cout << "AMBIGUOUS" << '\n';
  }
  else if(b < "13" && b > "00") cout << "YYMM" << '\n';
  else if(a < "13" && a > "00") cout << "MMYY" << '\n';
  else cout << "NA" << '\n';
}