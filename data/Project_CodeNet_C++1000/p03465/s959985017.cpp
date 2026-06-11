#include<cstdio>
#include<bitset>
using namespace std;
bitset<1<<21> s;
int sum;
int main()
{
    int n;
    s[0]=1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        s|=s<<x;
        sum+=x;
    }
    for(int i=(sum+1)>>1;i<=sum;++i)
    {
        if(s[i])
        {
            printf("%d",i);
            break;
        }
    }
}