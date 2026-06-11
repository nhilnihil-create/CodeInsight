#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;
struct propose
{
    int t, x, y;
};
int main(void)
{
    int N, a, b, c, time = 0, x = 0, y = 0, next = 0;
    cin >> N;
    vector<propose> vec(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b >> c;
        vec[i].t = a;
        vec[i].x = b;
        vec[i].y = c;
    }
    // for (int i = 0; i < N; ++i)
    //     cout << vec[i].t << " " << vec[i].x << " " << vec[i].y << "\n";
    while (true)
    {
        if (time == vec[next].t)
        {
            if (x == vec[next].x && y == vec[next].y)
            {
                if (time == vec.back().t)
                    break;
                next++;
            }
            else
            {
                cout << "No\n";
                return 0;
            }
        }
        if (x < vec[next].x)
            x++;
        else if (x > vec[next].x)
            x--;
        else if (y < vec[next].y)
            y++;
        else if (y > vec[next].y)
            y--;
        else
            x++;
        time++;
    }
    cout << "Yes\n";
}