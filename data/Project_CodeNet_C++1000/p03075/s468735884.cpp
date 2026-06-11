#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;

    bool res = e - a <= k;

    cout << (res ? "Yay!" : ":(") << "\n";
    return 0;
}
