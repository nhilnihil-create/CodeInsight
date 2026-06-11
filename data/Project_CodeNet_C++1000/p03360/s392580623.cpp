#include <bits/stdc++.h>
using namespace std;

int main() {
  long a,b,c,k;
  cin >> a >> b >> c >> k;
  for(long i=0;i<k;i++) {
    if(a>=b&&a>=c) a*=2;
    else if(b>=a&&b>=c) b*=2;
    else if(c>=a&&c>=b) c*=2;
  }
  cout << a+b+c << endl;
}