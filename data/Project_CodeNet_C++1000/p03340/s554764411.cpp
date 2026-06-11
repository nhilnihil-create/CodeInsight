#include<cstdio>
using namespace std;
int n;
long long a[200005];
int main()
{
    scanf("%d",&n);
    long long v=0,sum=0,e=1;
    int left=1,right=1;
    for(;right<=n;right++)
    {
        scanf("%d",&a[right]);
        while((v^a[right])!=v+a[right])
        {
            sum+=right-left;
            v^=a[left++];
        }
        v+=a[right];
    }
    printf("%lld",sum+e*(n-left+2)*(n-left+1)/2);
    return 0;
}
