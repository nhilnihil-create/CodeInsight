#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void bubble(int A[], int n)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = n-1; j >= i+1; j--)
      if(A[j] > A[j-1]) swap(A[j], A[j-1]);
  }
}

int main() 
{
  int n, a[100], sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  
  bubble(a,n);
  for(int i = 0; i < n; i++)
  {
    if(i%2 == 0) sum += a[i];
    else sum -= a[i];
  }
  cout << sum << endl;
}