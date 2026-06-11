#include <bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  for(int i=n; i<=999; i++){
    string s = to_string(i);
    if(s[0]==s[1] && s[1]==s[2]){
      cout << s << endl;
      return 0;
    }
  }
  cout << endl;
  return 0;
}