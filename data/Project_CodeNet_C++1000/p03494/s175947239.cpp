#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() 
{
  int n, min, A[200], ans[200] = {};
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> A[i];

  for(int i = 0; i < n; i++)
  {
    if(A[i]%2 == 0) 
    {
      A[i] /= 2;
      ans[i]++;
      i--;
    }
  }
  min = ans[0];
  for(int i = 1; i < n; i++)
    if(min > ans[i]) min = ans[i];

  cout << min << endl;
}