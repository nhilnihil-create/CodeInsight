#include <bits/stdc++.h>

using namespace std;
int main()
{
  int a,b;
  cin >> a >> b;
  int a2,b2;
  a2=a-1;
  b2=b-1;
  
  int ans1=a+a2;
  int ans2=a+b;
  int ans3=b+b2;
  cout << max({ans1,ans2,ans3}) << endl;
  return 0;
}