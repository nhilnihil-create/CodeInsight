#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s; cin >> s;
  int diff = 1000;
  for(int i=0; i<s.size()-2; i++) {
    int x;
  	x = (int)(s[i]-'0')*100+(int)(s[i+1]-'0')*10+(int)(s[i+2]-'0');
    diff = min(diff, abs(x-753));
  }
  cout << diff << endl;
  return 0;
}