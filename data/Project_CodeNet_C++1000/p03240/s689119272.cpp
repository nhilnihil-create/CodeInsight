#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> data(200, vector<int>(3));
  rep(i, n) cin >> data[i][0] >> data[i][1] >> data[i][2];
  int t;
  rep(i, n) if(data[i][2])
  {
    t = i;
    break;
  }
  
  for(int i = 0; i <= 100; i++)
  {
    for(int j = 0; j <= 100; j++)
    {
      bool flag = true;
      int h = data[t][2] + abs(data[t][0] - i) + abs(data[t][1] - j);
      rep(k, n)
      {
        int hh = max(h - abs(data[k][0] - i) - abs(data[k][1] - j), 0);
        if(hh != data[k][2])
        {
          flag = false;
          break;
        }
      }
      if(flag)
      {
        cout << i << " " << j << " " << h << endl;
        return 0;
      }
    }
  }
  
  cout << "illegal input" << endl;
           
  
  return 0;
}