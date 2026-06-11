#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,k;
  scanf("%d %d %d", &a,&b,&k);
  set<int> s;
  for ( int i=a; i<min(a+k,b+1); i++ ) {
    s.insert(i);
  }
  for ( int i=b; i>max(a,b-k); i-- ) {
    s.insert(i);
  }
  for ( auto &i:s ) {
    printf("%d\n", i);
  }
  return 0;
}