#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3E5;
int ans[MAXN];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (n < a + b - 1 || n > (long long) a * b)
        cout << -1 << endl;
    else
    {
        int extra = n - (a + b - 1);
        for (int i = 0; i < b; i++)
        {
            ans[i] = b - i;
        }
        int ind = b;
        for (int i = 0; i < a - 1; i++)
        {
            int len = min(extra + 1, b);
            extra = max(0, extra - (b - 1));
            int start = ind + len;
            for (int j = 0; j < len; j++)
            {
                ans[ind++] = start--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
