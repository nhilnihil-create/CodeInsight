#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int a,b,c,d,e,f,g,h;
  cin >> a >> b >> c >> d;
  e = c - (d - b);
  f = d + c - a;
  g = e - (f - d);
  h = f + e - c;
  cout << e << " " << f << " " << g << " " << h << endl;
  return 0;
}