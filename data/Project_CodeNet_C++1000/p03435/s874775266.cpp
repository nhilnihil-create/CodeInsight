#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    const int col = 3;
    const int row = 3;
    int mn1 = INF;
    int mn2 = INF;
    int mn3 = INF;
    vector<vector<int>> box(col, vector<int>(row));
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> box[i][j];
            if (i == 0)
            {
                mn1 = min(mn1, box[i][j]);
            }
            if (i == 1)
            {
                mn2 = min(mn2, box[i][j]);
            }
            if (i == 2)
            {
                mn3 = min(mn3, box[i][j]);
            }
        }
    }
    // cij = ai + bj
    // -> cij - ai = bj
    // -> 各cijからaiを引いた数がすべて同じbjであれば成立する

    // aiを可能性のある最小値0に設定して、各行が同じ値であればOK
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (i == 0)
            {
                box[i][j] -= mn1;
            }
            if (i == 1)
            {
                box[i][j] -= mn2;
            }
            if (i == 2)
            {
                box[i][j] -= mn3;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = col - 1; j >= 1; j--)
        {
            if (box[j][i] != box[j - 1][i])
            {
                cout << "No" << endl;
                return (0);
            }
        }
    }
    cout << "Yes" << endl;
    return (0);
}