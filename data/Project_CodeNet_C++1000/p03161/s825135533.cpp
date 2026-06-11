#include<iostream>
#define INT_MAX 1000000
#include <cstring>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int arr[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];
  int cost[n];
  memset(cost, INT_MAX, sizeof cost);
  cost[0] = 0;
  for(int i=1; i<n; i++)
  {
    if (i<=k)
    {
      for(int j=0; j<i; j++)
        cost[i] = min(cost[i], abs(arr[i]-arr[j])+cost[j]);
    }
    else
    {
      for(int j=i-k; j<i; j++)
        cost[i] = min(cost[i], abs(arr[i]-arr[j])+cost[j]);
    }
  }
  cout<<cost[n-1];
  return 0;
}