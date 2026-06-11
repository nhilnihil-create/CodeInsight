#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  int nam0 = 0;
  for(int i=0; i<n; ++i){
    if(s[i] == '0') ++nam0;
  }
  int ans = min(nam0, n-nam0) * 2;
  cout << ans << endl;
}