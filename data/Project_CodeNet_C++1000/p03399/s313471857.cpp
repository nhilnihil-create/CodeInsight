#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;

int main()
{
  int a,b,c,d;
  int res=INF;
  cin >> a>>b>>c>>d;

  res = min(a+c,b+d);
  res = min(res, a+d);
  res = min(res, b+c);

  cout << res << endl;
}
