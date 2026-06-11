#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  char X,Y; cin >>X >>Y;
  if (X<Y) cout <<'<' <<endl;
  if (X>Y) cout <<'>' <<endl;
  if (X==Y) cout <<'=' <<endl;
  return 0;
}
