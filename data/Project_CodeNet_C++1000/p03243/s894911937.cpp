#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int ans = 111; ans <= 999; ans += 111)
        if (ans >= n)
        {
            cout << ans << endl;
            return 0;
        }
}