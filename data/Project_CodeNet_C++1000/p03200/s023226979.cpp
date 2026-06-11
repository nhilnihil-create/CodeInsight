#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int l = s.size();
  long long ans = 0;
  long long cntb = 0;
  for(int i = 0; i < l; i++){
    if(s.at(i) == 'B') cntb++;
    if(s.at(i) == 'W') ans += cntb;
  }
  
  cout << ans << endl;
}