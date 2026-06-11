#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  int d=b-a-1;
  // a+=d-d/2;
  // b-=d/2;
  if ( d%2 ) {
    puts("Alice");
  } else {
    puts("Borys");
  }
  return 0;
}