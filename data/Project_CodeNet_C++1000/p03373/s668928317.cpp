#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, big;
  long long int x, y, x_amari, y_amari, money, ans;
  long long int i, ooi, data_i, data_x, data_y;
  ans = INT_MAX;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> x;
  cin >> y;
  big = c*2;
  ooi = max(x, y);
  for(i=0; i<=ooi; i++)
  {
    x_amari = x-i;
    y_amari = y-i;
    if(x_amari < 0)x_amari = 0;
    if(y_amari < 0)y_amari = 0;
    money = big*i;
    money += a*x_amari;
    money += b*y_amari;
    ans = min(ans, money);
  }
  cout << ans << endl;
  return 0;
}