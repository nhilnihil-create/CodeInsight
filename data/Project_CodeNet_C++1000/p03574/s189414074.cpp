#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int h, w;
  string board[50];

  const int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
  const int dy[] = {0, 1, -1, 1, -1, 1, 0, -1};

  cin >> h >> w;

  rep(i, h)
    cin >> board[i];
  
  rep(i, w)
  {
    rep(j, h)
    {

      if(board[j][i] == '#')
        continue;

      int count=0;
      rep(k, 8)
      {
        int t = i+dx[k], t2 = j+dy[k];

        if(t<0 || t>=w)
          continue;
        if(t2<0 || t2>=h)
          continue;

        if(board[t2][t] == '#')
        {
          count++;
        }
      }

      board[j][i] = count + '0';

    }
  }

  rep(i, h)
  {
    cout << board[i] << endl;
  }

}
