#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  vector<int> x={a,b,c};
  sort(x.begin(),x.end());
  int sa=x[2]-x[1]+x[2]-x[0];
  if(sa%2==0)
  cout << sa/2 << endl;
  else
  cout << sa/2+2 << endl;
}