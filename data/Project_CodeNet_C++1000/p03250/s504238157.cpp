#include <bits/stdc++.h>
using namespace std;

int main() {
  long a,b,c,ans;
  cin >> a >> b >> c;
  ans=a*10+b+c;
  ans=max(ans,a+b*10+c);
  ans=max(ans,a+b+c*10);
  cout << ans << endl;
}