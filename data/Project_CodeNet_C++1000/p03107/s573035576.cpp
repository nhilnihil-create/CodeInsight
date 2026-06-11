#include<bits/stdc++.h>
using namespace std;

signed main() {
  string S; cin >> S;
  int r=0, b=0;
  for(auto c : S) {
    if(c=='0') r++;
    else b++;
  }
  cout << min(r,b) * 2 << endl;
}
