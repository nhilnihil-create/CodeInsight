#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  cin >> h >> w;
  
  int a,b;
  cin >> a >> b;
  
  int res = h * w - ( h * b + w * a - a * b ) ;
  
  cout << res << endl;
}