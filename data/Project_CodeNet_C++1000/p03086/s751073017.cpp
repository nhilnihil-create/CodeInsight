#include <bits/stdc++.h>
using namespace std;

int main(){
  int ans;
  string s;
  cin >> s;
  int cnt = 0;
  for(auto a : s){
    if (a == 'A' || a == 'T' || a == 'G' || a == 'C'){
      cnt++;
    }
    else{
      if (ans<cnt) ans = cnt;
      cnt = 0;
    }
  }
  if (ans<cnt) ans = cnt;
  cout << ans << '\n';
  return 0;
}