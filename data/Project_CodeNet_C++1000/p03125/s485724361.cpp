#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int a, b;
  cin >> a >> b;
  if(b%a==0) cout << a + b << endl;
  else cout << b - a << endl;
  return 0;
}