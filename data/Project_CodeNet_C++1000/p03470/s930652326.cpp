#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() 
{
  int n, ans = 0, d[100];
  cin >> n;
  for(int i = 0; i < n; i++) cin >> d[i];
  
  for(int i = 0; i < n; i++)
  {
    for(int j = i+1; j < n; j++)
      if(d[i] == d[j]) d[j] = 0;
  }
  for(int i = 0; i < n; i++)
    if(d[i] != 0) ans++;
  cout << ans << endl;
}