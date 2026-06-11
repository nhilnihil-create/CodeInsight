#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main()
{   
   int x, y;
    cin >> x >> y;
 
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};
 
    vector<string> board(x);
    rep(i, x) cin >> board[i];
 
    rep(i, x)
    {
        rep(j, y)
        {
            rep(k, 4)
            {
                int xx = i + dx[k];
                int yy = j + dy[k];
                if (0 <= xx && xx < x && 0 <= yy && yy < y && board[i][j] == '#' && (board[xx][yy] == '#' || board[xx][yy] == 'O'))
                {
                    board[i][j] = 'O';
                    board[xx][yy] = 'O';
                }
            }
        }
    }
 
    rep(i, x)
    {
        rep(j, y)
        {
            if (board[i][j] == '#')
            {
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    cout << "Yes" << '\n';

    return 0;
}