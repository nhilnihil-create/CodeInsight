#include <bits/stdc++.h>

using namespace std;

int main(){

  char x,y;
  cin >> x >> y;

  if(x < y)cout << "<\n";
  if(x > y)cout << ">\n";
  if(x == y) cout << "=\n";

  return 0;
}
