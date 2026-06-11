#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    int x, y;
    cin >> x >> y;
    if (x % y == 0)
        cout << -1 << endl;
    else
        cout << x << endl;
    // end

    return 0;
}
