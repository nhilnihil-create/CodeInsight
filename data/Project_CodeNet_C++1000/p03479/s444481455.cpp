#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int64_t X, Y, r;
  cin >> X >> Y;
  r=Y/X;
  int s=0;
  while(r>0) {
    r/=2;
    s++;
  }
  cout << s << endl;
}
  