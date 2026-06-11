#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int ca = x / 500;
  if(ca > a){ca = a;}
  int i, j, k;
  int count = 0;
  for(i = 0; i <= ca; i++){
    int x1 = x - 500 * i;
    int cb = x1 / 100;
    if(cb > b){cb = b;}
    for(j = 0; j <= cb; j++){
      int x2 = x1 - 100 * j;
      if(x2 % 50 == 0 && x2/50 <= c){count++;}
    }
  }
  cout << count << endl;
  return 0;
}
