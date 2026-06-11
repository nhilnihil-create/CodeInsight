
#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;
int main(void) {
  int n, h, w;
  cin >> n >> h >> w;
  int res = 0;
  REP(i, n) {
    int a, b;
    cin >> a >> b;
    if(a >= h && b >= w) {
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}
