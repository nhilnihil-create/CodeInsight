#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
