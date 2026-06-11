#include <bits/stdc++.h>
using namespace std;

int	main()
{
  int	n, x, m_min, iv;
  vector<int> m;
  
  cin >> n >> x;  
  cin >> iv;
  m.push_back(iv);
  m_min = m.at(0);
  for (int i = 1; i < n; i++)
  {
    cin >> iv;
    m.push_back(iv);
    if (m.at(i) < m_min)
      m_min = m.at(i);
  }
  cout << n + (x - accumulate(m.begin(), m.end(), 0)) / m_min << endl;
  return (0);
}