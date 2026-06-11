#include<bits/stdc++.h>
using namespace std;

int main()
{
  int k, ans, deka, goke;
  vector<int> a(3);
  int i;
  goke = 0;
  for(i=0; i<3; i++)
  {
    cin >> a[i];
    goke += a[i];
  }
  cin >> k;
  deka = 0;
  for(i=0; i<3; i++)
  {
    if(deka < a[i])deka = a[i];
  }
  goke -= deka;
  for(i=0; i<k; i++)
  {
    deka *= 2;
  }
  ans = deka+goke;
  cout << ans << endl;
  return 0;
}