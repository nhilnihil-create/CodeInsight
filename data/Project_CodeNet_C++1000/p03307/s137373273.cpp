#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N; cin >>N;
  if (!(N%2)) cout <<N <<endl;
  else cout <<N*2 <<endl;
  return 0;
}
