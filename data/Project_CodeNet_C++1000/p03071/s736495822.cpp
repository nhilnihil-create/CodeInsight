#include <bits/stdc++.h>
using namespace std;

int main() {
 int a, b;
  cin >> a >> b;
  int ans = 0;
  if(a<=b) {
    ans +=b;
    --b;
  }
  else{
 ans +=a;
    --a;
  }
 if(a<=b) {
    ans +=b;
  }
  else ans +=a;
  cout << ans << endl;
}