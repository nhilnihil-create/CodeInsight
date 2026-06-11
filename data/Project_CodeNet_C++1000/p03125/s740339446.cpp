#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int ans = b - a;
  if(b%a == 0) ans = a + b;
  cout << ans << endl;
}
