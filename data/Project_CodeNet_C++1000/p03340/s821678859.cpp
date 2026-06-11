#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define m(a,b) memset(a,b,sizeof a)
#define en '\n'
using namespace std;
typedef long long ll;
const int N=2e5+5;
int a[N];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l=1,r=1,tmp=0;ll sum=0;
    while(r<=n)//枚举l,找到最优的r.
    {
        while((a[r]^tmp)==(a[r]+tmp)&&r<=n)
            tmp^=a[r],r++;
        if(r!=n+1)
            sum+=r-l;//分别指区间[l,r-1],[l+1,r-1],[l+2,r-1]....[r-1,r-1].
        else
            sum+=(ll)(r-l)*(ll)(r-l+1)/(ll)2;//因为r==n+,要break了,所以不能只加以l为起点向r-1扩展的,还应加从l+1,l+2...r-1出发的,故sum+=r-l+r-(l+1)+r-(l+2)+...+r-(r-1).
        tmp^=a[l],l++;//tmp的值把异或的a[l]去掉,l右移.
    }
    printf("%lld\n",sum);
}