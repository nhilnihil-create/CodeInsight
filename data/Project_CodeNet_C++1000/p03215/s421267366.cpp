#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000 + 10;
ll a[N], b[N * N], sum[N];

int x;

bool cmp(ll a, ll b) { return ((a >> x) & 1) > ((b >> x) & 1); }

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    int nn = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            b[nn++] = sum[j] - sum[i - 1];
            // cout<<b[nn - 1]<<" ";
        }
    // cout<< endl;
    // cout<<nn<<endl;
    ll ans = 0;
    for (x = 50; x >= 0; x--)
    {
        sort(b, b + nn, cmp);

        int cnt = 0;
        for (int i = 0; i < nn; i++)
            if ((b[i] >> x) & 1)
                cnt++;

        if (cnt < k)
            ans <<= 1;
        else
        {
            ans <<= 1;
            ans++;
            nn = cnt;
        }
    }
    printf("%lld", ans);
}