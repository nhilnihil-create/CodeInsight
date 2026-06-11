#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
  long long int n,max = 0,ans = 0;
  cin >> n;
  
  vector<long long int> p(n);
  for(int i = 0; i < n; i++)
  {
    cin >> p[i];
  }
  
  for(int i = 0; i < n; i++)
  {
    if(p[max] < p[i])
    {
      max = i;
    }
  }
  
  p[max] /= 2;
  
  for(int i = 0; i < n; i++)
  {
    ans += p[i];
  }
  
  cout << ans;
}