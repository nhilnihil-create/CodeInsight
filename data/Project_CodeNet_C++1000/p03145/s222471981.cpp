#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c ,s;
  cin >> a >> b >> c;
  s = min ( a*b , min ( b*c , a*c)) ;
  cout << s/2 << endl;
}
  
