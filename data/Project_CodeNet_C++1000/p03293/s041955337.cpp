#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t,ans="No";
  cin >> s >> t;
  for(long i=0;i<150;i++) {
    if(s==t) ans="Yes";
    char a=s.back();
    auto b=s.end();
    b--;
    s.erase(b);
    s=a+s;
  }
  cout << ans << endl;
}