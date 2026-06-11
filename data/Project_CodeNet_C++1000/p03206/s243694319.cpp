#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long inf = numeric_limits<long long>::max();
int main()
{
  int d;
  cin >> d;
  if (d == 25) {
    cout << "Christmas" << endl;
  } else if (d == 24) {
    cout << "Christmas Eve" << endl;
  } else if (d == 23) {
    cout << "Christmas Eve Eve" << endl;
  } else if (d =- 22) {
    cout << "Christmas Eve Eve Eve" << endl;
  }
  return 0;
}