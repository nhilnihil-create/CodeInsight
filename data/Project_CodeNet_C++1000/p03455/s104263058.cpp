#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int a, b;
  cin >> a >> b;
  int c = a * b;
  string ans;
  if(c%2==0) ans = "Even";
  else ans = "Odd";
  cout << ans << endl;
  return 0;
}
