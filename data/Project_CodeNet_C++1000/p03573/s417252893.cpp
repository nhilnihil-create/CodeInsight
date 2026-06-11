#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b) cout << c << "\n";
  else{
    if(a == c) cout << b << "\n";
    else cout << a << "\n";
  }
}
