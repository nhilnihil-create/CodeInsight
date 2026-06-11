#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, ans;
    cin >> n;
    if (n % 111 == 0)
        ans = n;
    else
    {
        ans = 111 * (n / 111 + 1);
    }
    cout << ans << endl;
}