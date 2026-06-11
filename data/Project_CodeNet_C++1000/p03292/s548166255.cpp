#include <bits/stdc++.h>
using namespace std;

int main () {
  int a,b,c;
  cin >> a >> b >> c;

  cout << min({abs(a-b)+abs(c-a),abs(a-c)+abs(b-a),
    abs(b-a)+abs(c-b),abs(b-c)+abs(a-b),
    abs(c-a)+abs(b-c),abs(c-b)+abs(a-c)}) << endl;

  return 0;
}
