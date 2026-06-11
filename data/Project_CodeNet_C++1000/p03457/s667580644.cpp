#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int N;
    cin >> N;
    N++;

    vector<int> time(N);
    vector<int> x(N);
    vector<int> y(N);

    time[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for (int i = 1; i < N; i++)
    {
        cin >> time[i] >> x[i] >> y[i];
    }

    int turn;
    int diff_x;
    int diff_y;
    int dis;
    for (int i = 0; i < N - 1; i++)
    {
        turn = time[i + 1] - time[i];
        diff_x = abs(x[i + 1] - x[i]);
        diff_y = abs(y[i + 1] - y[i]);
        dis = diff_x + diff_y;
        // printf("turn = %d, dis = %d\n", turn, dis);

        if (turn < dis)
        {
            cout << "No" << endl;
            return (0);
        }
        else
        {
            int diff = turn - dis;
            if (diff % 2 == 0)
            {
                continue;
            }
            else
            {
                cout << "No" << endl;
                return (0);
            }

            // if (turn % 2 == 0)
            // {
            //     if (dis % 2 == 0)
            //     {
            //         // even & even
            //         // possbile
            //         continue;
            //     }
            //     else
            //     {
            //         // even & odd
            //         cout << "No" << endl;
            //         return (0);
            //     }
            // }
            // else
            // {
            //     if (dis % 2 == 0)
            //     {
            //         // odd & even
            //         cout << "No" << endl;
            //         return (0);
            //     }
            //     else
            //     {
            //         // odd & odd
            //         // possible
            //         continue;
            //     }
            // }
        }
    }
    cout << "Yes" << endl;
    return (0);
}