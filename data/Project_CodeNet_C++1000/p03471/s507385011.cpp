#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N,Y;
  cin >> N >> Y;
  FOR(x,0,N+1) {
    FOR(y,0,N+1-x) {
      if (x*10000 + y*5000 + (N-x-y)*1000 == Y) {
        cout << x << " " << y << " " << N-x-y << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
  return 0;
}