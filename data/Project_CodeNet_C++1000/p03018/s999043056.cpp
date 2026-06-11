#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(void){
  string s;
  cin >> s;
  ll n = s.size();
  ll res = 0, i = 0, an = 0;
  while(i < n){
    if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C'){
      res += an + 1;
      s[i] = 'B';
      s[i + 1] = 'C';
      s[i + 2] = 'A';
      i += 2;
    }
    else if (s[i] == 'A'){
      an++;
      i++;
    }
    else {
      an = 0;
      i++;
    }
  }

  cout << res << endl;

  return 0;
}