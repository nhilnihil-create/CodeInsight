#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() 
{
  int n, a[100], sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  for(int j = 0; j < n; j++)
  {
    int max = 0;
    for(int i = 0; i < n; i++)
      if(max < a[i]) max = a[i];

    for(int i = 0; i < n; i++)
    {
      if(a[i] == max)
      {
        a[i] = 0;
        break;
      }
    }
    if(j%2 == 0) sum += max;
    else sum -= max;
  }
  cout << sum << endl;
}