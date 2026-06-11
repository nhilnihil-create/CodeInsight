#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN + 1];
long long pre[MAXN + 1];

long long getSum(int l, int r)
{
    if (l > r)
        return 0;
    return pre[r] - pre[l - 1];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    long long ans = 1E18;
    for (int i = 3; i <= n - 1; i++)
    {
        long long half = pre[i - 1];
        int x = 1;
        for (int jump = i / 2 + 1; jump > 0; jump /= 2)
        {
            while (x + jump <= i - 3 && pre[x + jump] <= half - pre[x + jump])
                x += jump;
        }
        if (abs(getSum(1, x) - getSum(x + 1, i - 1)) > abs(getSum(1, x + 1) - getSum(x + 2, i - 1)))
            x++;
        int y = i;
        half = getSum(1, n) - half;
        for (int jump = (n - i) / 2 + 1; jump > 0; jump /= 2)
        {
            while (y + jump <= n - 2 && getSum(i, y + jump) <= half - getSum(i, y + jump))
                y += jump;
        }
        if (abs(getSum(i, y) - getSum(y + 1, n)) > abs(getSum(i, y + 1) - getSum(y + 2, n)))
            y++;
        long long minn, maxx;
        minn = maxx = getSum(1, x);
        minn = min(minn, getSum(x + 1, i - 1));
        maxx = max(maxx, getSum(x + 1, i - 1));
        minn = min(minn, getSum(i, y));
        maxx = max(maxx, getSum(i, y));
        minn = min(minn, getSum(y + 1, n));
        maxx = max(maxx, getSum(y + 1, n));
        ans = min(ans, maxx - minn);
    }
    cout << ans << endl;
    return 0;
}
