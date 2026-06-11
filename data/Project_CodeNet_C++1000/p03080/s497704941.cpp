#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
int main()
{
    int n,R=0,B=0;
    char c;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&c);
        if(c=='R')
            R++;
        else
            B++;
    }

    if(R>B)printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
