#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int N, a, b;

int main()
{

    cin >> N >> a >> b;

    int ans = abs(a - b) % 2;
    // cout << ans << endl;
    if (ans == 0)
    {
        cout << "Alice" << endl;
    }
    else if (ans == 1)
    {
        cout << "Borys" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }

    return 0;
}
