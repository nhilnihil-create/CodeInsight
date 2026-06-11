#include <bits/stdc++.h>

using namespace std;

int a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    if(a >= 13)
        cout << b;
    else if(a >= 6)
        cout << b / 2;
    else
        cout << 0;

    return 0;
}
