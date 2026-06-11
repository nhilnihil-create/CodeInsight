#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a, b, c, d;
  cin >> a >> b;
  c=a; d=b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  
  if (b==c && a==d) cout << "YES" << endl;
  else cout << "NO" << endl;
}
