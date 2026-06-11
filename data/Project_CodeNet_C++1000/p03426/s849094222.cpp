#include <iostream>
#include <string>

using namespace std;

int main()
{
    int h, w, D;
    cin >> h >> w >> D;
    int a;
    int px[90001], py[90001];
    int d[90001];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a;
            px[a] = i;
            py[a] = j;
        }
    }

    for (int i = (D + 1); i <= h * w; i++)
    {
        d[i] = d[i - D] + abs(px[i] - px[i - D]) + abs(py[i] - py[i - D]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << d[r] - d[l] << endl;
        // cout << "q:" << q << endl;
    }
    return 0;
}