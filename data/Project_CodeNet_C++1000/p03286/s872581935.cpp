#include<bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int main() {
  int n; cin >> n;

  string s="";
  while(n) {
    if(n%-2) {
      --n;
      s = "1"+s;
    } else {
      s = "0"+s;
    }
    n/=-2;
  }
  if(s == "")	s = "0";
  cout << s << endl;
}
