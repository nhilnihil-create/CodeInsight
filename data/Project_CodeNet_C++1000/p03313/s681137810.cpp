#include <bits/stdc++.h>

using namespace std;

const int MAXN = 18;
int a[1 << MAXN];
int ans[1 << MAXN];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < (1 << n); i++)
    {
        int big1 = a[0];
        int big2 = a[i];
        if (big1 < big2)
            swap(big1, big2);
        int sub = i & (i - 1);
        while (sub > 0)
        {
            int x = a[sub];
            if (x > big2)
            {
                big2 = x;
                if (big1 < big2)
                    swap(big1, big2);
            }
            sub = i & (sub - 1);
        }
        ans[i] = big1 + big2;
    }
    int t = ans[1];
    for (int i = 1; i < (1 << n); i++)
    {
        t = max(t, ans[i]);
        cout << t << "\n";
    }
    return 0;
}
