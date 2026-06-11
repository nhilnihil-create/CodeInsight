#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d; cin >> a >> b >> c >> d;
  int x = abs(a-b);
  int y = abs(b-c);
  if(a<b&&b<c){
    if(x<=d&&y<=d) cout << "Yes";
    else cout << "No";
  }
  else {
    if(abs(a-c)<=d) cout << "Yes";
    else cout << "No";
  }
}