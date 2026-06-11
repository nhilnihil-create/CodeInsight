#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin >> s;
  bool ans  = true;
  int cnt = 0;
  if(s.front() != 'A') ans = false;
  else {
    for(int i = 2; i <= s.size()-2; i++){
      if(s.at(i) == 'C')cnt++;
    }
    if(cnt != 1) ans = false;
  }
  cnt = 0 ;
  rep(i,s.size()){
    if(isupper(s.at(i))) cnt++;
  }
  if(cnt != 2) ans = false;
  puts(ans?"AC":"WA");
 }
