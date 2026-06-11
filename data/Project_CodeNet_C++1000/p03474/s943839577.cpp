#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  for ( int i=0; i<n+m+1; i++ ) {
    if ( i==n ) {
      if ( s[i]!='-' ) {
        puts("No");
        return 0;
      }
    }
    else if ( !isdigit(s[i]) ) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}