#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> s;
  for (int i = 0; i < h; i++)
  {
    string buf;
    cin >> buf;
    s.push_back(buf);
  }

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      char cnt = '0';
      if (s.at(i).at(j) == '.')
      {

        if (i - 1 >= 0 && j - 1 >= 0)
        {
          if (s.at(i - 1).at(j - 1) == '#')
          {
            cnt++;
          }
        }
        if (i - 1 >= 0)
        {
          if (s.at(i - 1).at(j) == '#')
          {
            cnt++;
          }
        }
        if (i - 1 >= 0 && w > j + 1)
        {
          if (s.at(i - 1).at(j + 1) == '#')
          {
            cnt++;
          }
        }
        if (j - 1 >= 0)
        {
          if (s.at(i).at(j - 1) == '#')
          {
            cnt++;
          }
        }
        if (w > j + 1)
        {
          if (s.at(i).at(j + 1) == '#')
          {
            cnt++;
          }
        }
        if (h > i + 1 && j - 1 >= 0)
        {
          if (s.at(i + 1).at(j - 1) == '#')
          {
            cnt++;
          }
        }
        if (h > i + 1)
        {
          if (s.at(i + 1).at(j) == '#')
          {
            cnt++;
          }
        }
        if (h > i + 1 && w > j + 1)
        {
          if (s.at(i + 1).at(j + 1) == '#')
          {
            cnt++;
          }
        }
        s.at(i).at(j) = (char)cnt;
      }
    }
  }
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cout << s.at(i).at(j);
    }
    cout << endl;
  }
}
