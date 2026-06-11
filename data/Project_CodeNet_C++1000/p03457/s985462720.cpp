#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const double PI = (acos(-1));
const long long MOD = pow(10, 9) + 7;
long long kaizyou(int N);
long long POW(int J);

bool judge(int dt, int dx, int dy);

int main()
{
    int N;
    cin >> N;
    int t[N + 1], x[N + 1], y[N + 1];

    t[0] = 0;
    x[0] = 0;
    y[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }

    int dt, dx, dy;
    bool result = true;
    for (int i = 0; i < N; i++)
    {
        dt = t[i + 1] - t[i];
        dx = x[i + 1] - x[i];
        dy = y[i + 1] - y[i];

        if (judge(dt, dx, dy))
        {
            continue;
        }
        else
        {
            result = false;
            break;
        }
    }

    if (result)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}

bool judge(int dt, int dx, int dy)
{
    int dl = abs(dx) + abs(dy);

    if (dl <= dt && (dl % 2 == dt % 2))
    {
        //cout << "true";
        return true;
    }
    else
    {
        //cout << "false";
        return false;
    }
}
