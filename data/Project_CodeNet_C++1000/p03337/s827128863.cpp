#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, ans;
    cin >> a >> b;
    ans = max(a + abs(b), a * b);
    cout << ans;

    return 0;
}