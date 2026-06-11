#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int numBits;
int a[MAXN];
int b[MAXN];

bool cmp(int a, int b)
{
    return (a % (1 << numBits)) < (b % (1 << numBits));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int ans = 0;
    for (int i = 0; i <= 28; i++)
    {
        numBits = i + 1;
        sort(a, a + n, cmp);
        sort(b, b + n, cmp);
        int cur = n - 1;
        int p1, p2, p3;
        p1 = p2 = p3 = 0;
        while (cur >= 0)
        {
            int key = a[cur] % (1 << numBits);
            while (p1 < n && b[p1] % (1 << numBits) + key < (1 << i))
                p1++;
            while (p2 < n && b[p2] % (1 << numBits) + key < (1 << (i + 1)))
                p2++;
            while (p3 < n && b[p3] % (1 << numBits) + key < (1 << i) + (1 << (i + 1)))
                p3++;
            int num = p2 - p1 + n - p3;
            if (num % 2 != 0)
                ans ^= (1 << i);
            cur--;
        }
    }
    cout << ans << endl;
    return 0;
}
