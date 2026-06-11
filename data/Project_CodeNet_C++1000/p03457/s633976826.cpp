#include <bits/stdc++.h>
using namespace std;

int N;
int t[100010], x[100010], y[100010];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
    }

    t[0] = 0;
    x[0] = 0, y[0] = 0;

    for (int i = 0; i + 1 <= N; i++)
    {
        int dt = t[i + 1] - t[i];
        int dx = abs(x[i + 1] - x[i]);
        int dy = abs(y[i + 1] - y[i]);

        if (dt < dx + dy || dt % 2 != (dx + dy) % 2)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
