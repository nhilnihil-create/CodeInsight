#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a + b == c + d) cout << "Balanced" << endl;
  else if (a + b > c + d) cout << "Left" << endl;
  else if (a + b < c + d) cout << "Right" << endl;
}
