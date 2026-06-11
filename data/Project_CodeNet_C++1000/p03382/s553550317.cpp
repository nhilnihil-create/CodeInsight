#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, a[100005];

int BS_low(int x)
{
    int l = 1, r = n, mid, save = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] <= x)
        {
            l = mid + 1;
            save = mid;
        }
        else r = mid - 1;
    }
    return a[save];
}

int BS_high(int x)
{
    int l = 1, r = n, mid, save = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] >= x)
        {
            r = mid - 1;
            save = mid;
        }
        else l = mid + 1;
    }
    return a[save];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int low = 0, high = 0, mid = (a[n] + 1) / 2;
    low = BS_low(mid);
    high = BS_high(mid);
    if (mid - low <= high - mid) printf("%d %d", a[n], low); else printf("%d %d", a[n], high);
	return 0;
}
