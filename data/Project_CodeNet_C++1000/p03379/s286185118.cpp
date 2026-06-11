#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
    y[i] = x[i];
  }
  sort(y.begin(), y.end());
  int mean1 = y[n/2 - 1];  
  int mean2 = y[n/2];  
  for (auto && a : x)
  {
    if (a <= mean1)
    {
      cout << mean2 << endl;
    }
    else
    {
      cout << mean1 << endl;
    }
  }
    
}