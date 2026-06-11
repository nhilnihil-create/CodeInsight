#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    int a, b;
    cin >> a >> b;
    if (a + b == 15)
        cout << '+';
    else if (a * b == 15)
        cout << '*';
    else
        cout << 'x';
    cout << endl;
    // end

    return 0;
}
