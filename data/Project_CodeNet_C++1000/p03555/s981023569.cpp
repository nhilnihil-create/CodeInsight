#include <bits/stdc++.h>
using namespace std;
#include <stdio.h>
int main() {char s[3],t[3];
    for(int i; i<3; i++){
      cin >> s[i];
    }
  for(int j; j<3; j++){
      cin >> t[j];
    }
  if(s[1]==t[1]&&s[0]==t[2]&&s[2]==t[0]) cout << "YES" << endl;
  else cout << "NO" << endl;
}

