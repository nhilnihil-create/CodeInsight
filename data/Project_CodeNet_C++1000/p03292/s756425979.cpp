#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int min = 9999;
  int tmp;
  
  tmp = abs(b-a) + abs(c-b); if (tmp < min) min = tmp;
  tmp = abs(c-a) + abs(b-c); if (tmp < min) min = tmp;
  tmp = abs(a-b) + abs(c-a); if (tmp < min) min = tmp;
  tmp = abs(c-b) + abs(a-c); if (tmp < min) min = tmp;
  tmp = abs(a-c) + abs(b-a); if (tmp < min) min = tmp;
  tmp = abs(b-c) + abs(a-b); if (tmp < min) min = tmp;
  
  cout << min << endl;
}