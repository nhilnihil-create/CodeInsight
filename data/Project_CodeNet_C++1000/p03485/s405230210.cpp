#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >> b;
  double ans;
  double c = double(a), d = double(b);
  ans = (c+d)/2;
  if(ans - ((a+b)/2) > 0){
    ans++;
  }
  cout << int(ans) << endl;
}