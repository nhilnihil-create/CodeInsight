#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    cout << min(b / a, c);

    return 0;
}
