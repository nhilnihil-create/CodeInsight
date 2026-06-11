#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s; int maximum=0, l=0;
  for(int i=0;i<s.size();i++){
    if(s[i] != 'A' && s[i] != 'T' && s[i] != 'G' && s[i] != 'C') {l=0; continue;}
    l++; maximum = max(maximum, l);
  }
  cout << maximum << endl;
  return 0;
}