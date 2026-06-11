#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = long long;

int calc(int r, int D, int x, int count)
{
    if (count == 0)
    {
        return 0;
    }

    int nx = r * x - D;

    cout << nx << endl;

    return calc(r, D, nx, --count);
}

int main()
{
    int r, D, x;
    cin >> r >> D >> x;

    calc(r, D, x, 10);

    return 0;
}
