#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;
int n,a[maxn],ans,S[maxn * 10],top,num[maxn * 10];

bool check(int limit)
{
    memset(S,0,sizeof(S));
    memset(num,0,sizeof(num));
    top = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i - 1])
            continue;
        int x = a[i];
        while (top && S[top] > x)
            top--;
        while (top && S[top] == x && num[top] == limit)
        {
            top--;
            x--;
        }
        if (!x)
            return false;
        if (S[top] < x)
        {
            S[++top] = x;
            num[top] = 2;
            if (limit == 1)
                return false;
        }
        else
        {
            num[top]++;
            if (num[top] > limit)
                return false;
        }

    }
    return true;
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    int l = 1,r = n;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    printf("%d\n",ans);

    return 0;
}
