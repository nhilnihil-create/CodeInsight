#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
  int n;
  double ans = 0.0;
  cin >> n;
  
  vector<double> x(n);
  vector<string> u(n);
  for(int i = 0; i < n; i++)
  {
    cin >> x[i] >> u[i];
    
    if(u[i] == "JPY")
    {
      ans += x[i];
    }
    else if(u[i] == "BTC")
    {
      ans += (x[i] * 380000.0);
    }
  }
  
  cout << ans;
}