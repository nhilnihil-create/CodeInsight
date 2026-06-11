#include<cmath>
#include<iostream>
using namespace std;
int main()
{
  int a, b, c, d, e, k;
  cin >> a >> b >> c >> d >> e >> k;
  if(abs(a - b) > k ||
     abs(a - c) > k ||
     abs(a - d) > k ||
     abs(b - c) > k ||
     abs(b - d) > k ||
     abs(b - e) > k ||
     abs(c - d) > k ||
     abs(c - e) > k ||
     abs(d - e) > k ||
     abs(e - a) > k)
    cout << ":(";
  else
    cout << "Yay!";
  return 0;
}