#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v(4);
  for(int i=0; i<4; i++) cin >> v[i];
  sort(v.begin(), v.end());
  
  bool can = true;
  for(int i=0; i<4; i++) {
    if(i==0) {
      if(v[i]!=1) can = false;
    }
    if(i==1) {
      if(v[i]!=4) can = false;
    }
    if(i==2) {
      if(v[i]!=7) can = false;
    }
    if(i==3) {
      if(v[i]!=9) can = false;
    }
  }
  if(can) cout << "YES" << endl;
  else cout << "NO" << endl;
}