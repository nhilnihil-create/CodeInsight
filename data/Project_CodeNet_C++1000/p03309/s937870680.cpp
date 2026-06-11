#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 200010;
const double eps = 1e-6;

int n;
int a[N];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        a[i] -= i;
    }
    sort(a + 1, a + 1 + n);

    int b = a[(n + 1) / 2];

    LL res = 0;
    for(int i = 1; i <= n; i++) res += abs(b - a[i]);
    cout << res << endl;
    return 0;
}
