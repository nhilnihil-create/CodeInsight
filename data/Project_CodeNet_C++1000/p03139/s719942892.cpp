#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  cout << min(b,c) << " ";
  if (a<b+c) cout << b+c-a << endl;
  else cout << 0 << endl;
}