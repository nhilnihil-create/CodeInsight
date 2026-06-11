#include <bits/stdc++.h>
using namespace std;
int main(){
  string s; cin >> s;
  int res = 700;
  for(char x : s){
    if(x == 'o') res += 100;
  }
  cout << res << endl;
  return 0;
}