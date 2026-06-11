#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int l = a + b;
  int r = c + d;
  string ans;
  if(l<r) ans = "Right";
  if(l==r) ans = "Balanced";
  if(l>r) ans = "Left";
  cout << ans << endl;
  return 0;
}
