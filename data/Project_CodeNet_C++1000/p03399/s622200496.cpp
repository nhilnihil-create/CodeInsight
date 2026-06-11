#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  int sum = 0;
  sum += min(a, b);
  sum += min(c, d);
  
  cout << sum << endl;
}