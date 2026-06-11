#include <bits/stdc++.h>
using namespace std;
int C[3][3];

int main()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> C[i][j];
    }
  }
  for (int i = 0; i < 2; i++)
  {
    vector<int> v;
    for (int j = 0; j < 3; j++)
    {
      v.push_back(C[i + 1][j] - C[i][j]);
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() != 1)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int j = 0; j < 2; j++)
  {
    vector<int> v;
    for (int i = 0; i < 3; i++)
    {
      v.push_back(C[i][j + 1] - C[i][j]);
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() != 1)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
