#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int sum1[N], sum2[N];

int main()
{
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> t;
        sum1[i] = sum1[i - 1] + t;
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> sum2[i];
    }    
    for (int i = n - 1;i > 0;i--)
        sum2[i] += sum2[i + 1];
    int maxn = 0;
    for (int i = 1;i <= n;i++)
        maxn = max(sum1[i] + sum2[i], maxn);
    cout << maxn;
    return 0;
}
