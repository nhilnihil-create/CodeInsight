#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> t(999);
    int sum = 0;
    for (int i = 1; i <= 999; i++)
    {
        sum += i;
        t[i] = sum;
        // cout << t[i] << endl;
    }
    int ans = 0;
    for (int i = 1; i < 999; i++)
    {
        if (t[i + 1] - t[i] == b - a)
        {
            ans = t[i] - a;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}