#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
  int n,T,min = 1000,count = 0;
  cin >> n >> T;
  
  vector<long long int> c(n);
  vector<long long int> t(n);
  for(int i = 0; i < n; i++)
  {
    cin >> c[i] >> t[i];
  }
  
  for(int i = 0; i < n; i++)
  {
    if(t[i] <= T)
    {
      if(c[i] < min)
      {
        min = c[i];
      }
    }
    else
    {
      count++;
    }
  }
  if(count == n)
  {
    cout << "TLE";
  }
  else
  {
    cout << min;
  }
  return 0;
}