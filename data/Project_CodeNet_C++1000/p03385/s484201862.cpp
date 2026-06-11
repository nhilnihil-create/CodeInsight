#include <bits/stdc++.h>
using namespace std;
int main(){
  string s; cin >> s;
  int f[3] = {0, 0, 0};
  for(char x : s){
    if(x == 'a') f[0] = 1;
    else if(x == 'b') f[1] = 1;
    else if(x == 'c') f[2] = 1;
  }
  if(f[0]&&f[1]&&f[2]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}