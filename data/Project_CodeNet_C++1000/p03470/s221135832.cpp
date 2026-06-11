#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() 
{
  int n,ans = 0,d[110],num[110] = {0};
  cin >> n;
  for(int i = 0; i < n; i++) cin >> d[i];

  for(int i = 0; i < n; i++)
    num[d[i]]++;

  for(int i = 1; i<= 100; i++)
    if(num[i] != 0) ans++;

  cout << ans << endl;
}