#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, ans;
    cin >> n >> m;
    for (int i = m / n; i > 0; --i)
    {
        if (m % i == 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}