#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,fn=0;
  cin >> n;
  for(long i=1;i<=n;i*=10) {
    fn+=n/i%10;
  }
  if(n%fn==0) cout << "Yes" << endl;
  else cout << "No" << endl;
}