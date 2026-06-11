#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  long ans=700;
  cin >> s;
  for(long i=0;i<3;i++) {
    if(s[i]=='o') ans+=100;
  }
  cout << ans << endl;
}