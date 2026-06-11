#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;



int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int l = a+b;
  int r = c+d;
  if(l>r) cout << "Left" << endl;
  else if(l == r) cout << "Balanced" << endl;
  else cout << "Right" << endl;
  return 0;
}
