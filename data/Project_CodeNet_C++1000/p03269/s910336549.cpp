#if 1

#include <bits/stdc++.h>
using namespace std;

int cnt[20];

inline int pcnt(int n)
{
    int ccnt = 0;
    for(int i = 19;i > 0;i--)
    {
        for(;n >= cnt[i];n -= cnt[i]) ccnt++;
    }
    return ccnt;
}
int main()
{
    int L;
    scanf("%d",&L);
    cnt[1] = 1;
    for(int i = 2;i <= 19;i++) cnt[i] = cnt[i-1] << 1;
    printf("20 %d\n",36 + pcnt(L));
    for(int i = 1;i <= 18;i++)
    {
        printf("%d %d %d\n",i,i+1,0);
        printf("%d %d %d\n",i,i+1,cnt[i]);
    }
    for(int i = 19;i > 0;i--)
    {
        for(;L >= cnt[i];)
        {
            L -= cnt[i],
            printf("%d %d %d\n",i,20,L);
        }
    }
    return 0;
}

#endif // 1++