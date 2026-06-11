#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if(a + b > c + d ) cout << "Left" << endl;
  else if(a + b == c + d ) cout << "Balanced" << endl;
  else cout << "Right" << endl;

  return 0;
}
