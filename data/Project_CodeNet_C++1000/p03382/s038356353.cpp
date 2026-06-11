#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define ll long long
#define mst(a) memset(a, 0, sizeof a)

const int mod = 1e9+7;
const int maxn = 1e5+50;
const int inf = 1e9;

int a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int min_d = inf;
    int ans = a[0];
    for (int i = 0; i < n-1; ++i)
    {
        int tmp = min(abs(a[n-1]/2 - a[i]), abs((a[n-1]+1)/2 - a[i]));
        if (tmp < min_d)
        {
            min_d = tmp;
            ans = a[i];
        }
    }
    printf("%d %d\n", a[n-1], ans);
    return 0;
}