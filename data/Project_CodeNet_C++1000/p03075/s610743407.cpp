#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int l[5];
    rep(i, 5) scanf("%d", &l[i]);
    int k;
    scanf("%d", &k);
    rep(i, 5)
    {
        rep(j, 5)
        {
            if (abs(l[i] - l[j]) > k)
            {
                printf(":(\n");
                return 0;
            }
        }
    }
    printf("Yay!\n");
    return 0;
}