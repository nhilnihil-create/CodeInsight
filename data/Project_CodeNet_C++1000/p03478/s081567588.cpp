#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b,sum=0;
  cin >> n >> a >> b;
  for ( int i=1; i<=n; i++ ) {
    int m=i,s=0;
    while ( m ) {
      s+=m%10;
      m/=10;
    }
    if ( s>=a&&s<=b ) sum+=i;
  }
  cout << sum << '\n';
  return 0;
}
