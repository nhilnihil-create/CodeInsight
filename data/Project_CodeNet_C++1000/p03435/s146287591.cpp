#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

//　全探索ver
int main(void)
{
    const int col = 3;
    const int row = 3;
    vector<vector<int>> box(col, vector<int>(row));
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> box[i][j];
        }
    }

    int b1, b2, b3;
    string ans = "No";
    for (int a1 = 0; a1 <= 100; a1++)
    {
        for (int a2 = 0; a2 <= 100; a2++)
        {
            for (int a3 = 0; a3 <= 100; a3++)
            {
                b1 = box[0][0] - a1;
                b2 = box[0][1] - a1;
                b3 = box[0][2] - a1;

                if ((box[0][0] - b1 == box[0][1] - b2 && box[0][1] - b2 == box[0][2] - b3) &&
                    (box[1][0] - b1 == box[1][1] - b2 && box[1][1] - b2 == box[1][2] - b3) &&
                    (box[2][0] - b1 == box[2][1] - b2 && box[2][1] - b2 == box[2][2] - b3))
                {
                    ans = "Yes";
                    cout << ans << endl;
                    return (0);
                }
            }
        }
    }
    cout << ans << endl;
}