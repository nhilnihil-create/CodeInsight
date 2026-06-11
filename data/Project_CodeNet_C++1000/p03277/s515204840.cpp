#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int BIAS = MAXN + 2;
int a[MAXN + 1];
int pre[MAXN + 1];
int bit[MAXN + BIAS + 1];

void inc(int pos, int amt)
{
    while (pos <= MAXN + BIAS)
    {
        bit[pos] += amt;
        pos += pos & -pos;
    }
}

int query(int pos)
{
    int ans = 0;
    while (pos > 0)
    {
        ans += bit[pos];
        pos -= pos & -pos;
    }
    return ans;
}

bool check(int n, int x)
{
    fill(bit, bit + MAXN + BIAS + 1, 0);
    long long pairs = 0;
    inc(BIAS, 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        if (a[i] <= x)
            pre[i]++;
        else
            pre[i]--;
        pairs += query(pre[i] - 1 + BIAS);
        inc(pre[i] + BIAS, 1);
    }
    return pairs > (long long) n * (n + 1) / 2 - pairs;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int jump = 1E9; jump > 0; jump /= 2)
    {
        while (ans + jump <= 1E9 && !check(n, ans + jump))
            ans += jump;
    }
    cout << ans + 1 << endl;
    return 0;
}
