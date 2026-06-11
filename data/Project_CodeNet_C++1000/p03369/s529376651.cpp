#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

  string s;

  cin >> s;

  int value = 700;

  for(int i=0;i<s.length();i++){
    if(s[i] == 'o'){
      value = value + 100;
    }
  }

  cout << value << endl;

}