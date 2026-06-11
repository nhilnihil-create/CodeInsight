#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  vector<int> vec(4);
  for(int i=0; i<6; i++) {
    cin >> a;
    vec[a]++;
  }
  bool ans=true;
  for(int i=0; i<=4; i++) {
    if(vec[i]>=3) ans=false;
  }
  if(ans) cout << "YES" << endl;
  else cout << "NO" << endl;
}