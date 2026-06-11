#include <bits/stdc++.h>
using namespace std;

int Sum(int n){
  
  int goukei = 0;
  
  goukei = (1 + n) * n / 2;
  
  return goukei;
  
}

int main() {
  
  int a,b,h,ans;
  cin >> a >> b;
  
  int n = b - a;
  
  h = Sum(n-1);
  
  ans = h - a;
  
  cout << ans << endl;

}