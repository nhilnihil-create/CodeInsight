#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string a, b, c;
  cin >> n >> a >> b >> c;
  int i;
  int ans = 0;
  for(i = 0; i < n; i++)
  {
    if(a.at(i) != b.at(i) && a.at(i) != c.at(i) && b.at(i) != c.at(i))ans += 2;
    else if(a.at(i) != b.at(i) || a.at(i) != c.at(i) || b.at(i) != c.at(i))ans++;
  }
  cout << ans << endl;
}