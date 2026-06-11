#include <bits/stdc++.h>
using namespace std;


int main()
{
  int n, x,count;
  cin >> n >> x;
  
  count = n;
  vector<int> m(n);
  for (int i = 0; i < n; i++)
  {
    cin >> m.at(i);
    x -= m.at(i);
  }

  sort(m.begin(), m.end());
  while (m.at(0) <= x)
  {
    
      x -= m.at(0);
      ++count;
    
  }
    cout << count << endl;
  }
