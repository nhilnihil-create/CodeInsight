#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  string s;
  ll k;
  cin >> s >> k;
  int pos = 0;
  int len = (int)s.length();
  for(int i = 0; i < len; ++i){
    if((s[i] - '0') > 1){
      pos = i;
      break;
    }
  }
  if(k < (ll)(pos + 1)) cout << '1' << '\n';
  else cout << s[pos] << '\n';
}