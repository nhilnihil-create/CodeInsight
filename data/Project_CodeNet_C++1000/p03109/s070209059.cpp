#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  string a = "2019/04/30";
  string res = (s>a) ? "TBD" : "Heisei";
  cout << res << endl;
  return 0;
}