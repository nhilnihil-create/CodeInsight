#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
using namespace std;
const int N = 1e5+7, M = 1e3;
int a[N];
vector<int> vec[M];
int main()
{
    int n;
    scanf("%d", &n);n *= 2;
    if(n==1)
    {
        puts("No");
        return 0;
    }
    for(int i = 1; i*(i+1) <= n; i++)
    {
        if(i*(i+1)==n)
        {
            puts("Yes");
            int siz = i, m = i+1, p = 0;
            for(int i = 1; i <= m; i++)
            {
                int last = p;
                while(vec[i].size()<siz)
                {
                    vec[i].push_back(++p);
                }
                for(int j = i+1; j <= m; j++)
                {
                    vec[j].push_back(++last);
                }
            }
            printf("%d\n", m);
            for(int i = 1; i <= m; i++)
            {
                printf("%d", siz);
                for(int j = 0; j < siz; j++)
                {
                    printf(" %d", vec[i][j]);
                }
                puts("");
            }
            return 0;
        }
    }
    puts("No");
    return 0;
}
