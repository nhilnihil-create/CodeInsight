#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 100010;
const double eps = 1e-6;

int n, a[N];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);

    int sum = 0;
    for(int i = 1; i <= n + 1; i++) sum += abs(a[i] - a[i - 1]);

    for(int i = 1; i <= n; i++)
        if(a[i - 1] < a[i] && a[i] < a[i + 1] || a[i - 1] > a[i] && a[i] > a[i + 1])
        {
            cout << sum << endl;
        }
        else
        {
            int d = min(abs(a[i - 1] - a[i]), abs(a[i + 1] - a[i]));
            cout << sum - 2 * d << endl;
        }
    return 0;
}
