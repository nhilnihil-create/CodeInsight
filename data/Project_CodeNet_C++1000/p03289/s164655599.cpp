#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  int len = s.size();
  bool ok = true;
  if(s.at(0) != 'A') ok = false;
  int cntc = 0;
  for(int i = 1; i < len; i++){
    if(isupper(s.at(i))){
      if(i == 1 || i == len - 1 || s.at(i) != 'C') ok = false;
      if(s.at(i) == 'C') cntc++;
    }
  }
  if(cntc != 1) ok = false;
  if(ok) cout << "AC" << endl;
  else cout << "WA" << endl;
}