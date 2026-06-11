#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() 
{
  int n,a,b,ans = 0;
  cin >> n >> a >> b;
  for(int i = 1; i <= n; i++)
  {
    int sum = 0;
    int x = i/10;
    int y = x/10;
    int z = y/10;
    if(i%10 != 0) sum += i%10;
    if(x%10 != 0) sum += x%10;
    if(y%10 != 0) sum += y%10;
    if(z%10 != 0) sum += z%10;
    if(z/10 != 0) sum += z/10;

    if(a <= sum && sum <= b) ans += i;
  }
  cout << ans << endl;
}