#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  string ans="";
  cin >> n;
  for(long i=-1;n!=0;i*=-2) {
    if(labs(n)%(labs(i)*2)==0) {
      ans='0'+ans;
    } else {
      ans='1'+ans;
      n+=i;
    }
  }
  if(ans=="") ans="0";
  cout << ans << endl;
}