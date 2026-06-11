#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


int main() {
  
  string S;
  cin >> S;

  for(int bit = 0;bit < (1<<4);bit++) {
    string a="",b="",c="",d="";
    if(bit&1) a = "A";
    if(bit>>1&1) b = "A";
    if(bit>>2&1) c = "A";
    if(bit>>3&1) d = "A";
    string s = a+"KIH"+b+'B'+c+'R'+d;
    if(S == s) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  
}