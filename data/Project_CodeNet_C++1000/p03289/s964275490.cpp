#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  bool ok = true;
  int l = s.size();
  int ccnt = 0;
  if(s.at(0) != 'A') ok = false;
  for(int i = 2; i < l-1; i++){
    if(s.at(i) == 'C') ccnt++;
  }
  if(ccnt != 1) ok = false;
  ccnt = 0;
  for(int i = 1; i < l; i++){
    char c = s.at(i);
    if(c < 'a') ccnt++;
    if(c > 'z') ccnt++;
  }
  if(ccnt != 1) ok = false;
  
  if(ok) cout << "AC" << endl;
  else cout << "WA"  << endl;
}