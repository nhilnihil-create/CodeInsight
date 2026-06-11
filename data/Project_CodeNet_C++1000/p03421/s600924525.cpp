//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define ll long long
#define mod 1000000007
#define C 0.5772156649
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
#define pil pair<int,ll>
#define pii pair<int,int>
#define ull unsigned long long
#define base 1000000000000000000
#define fio ios::sync_with_stdio(false);cin.tie(0)

using namespace std;

const double g=10.0,eps=1e-12;
const int N=300000+10,maxn=100000+10,inf=0x3f3f3f3f,INF=0x3f3f3f3f3f3f3f3f;

int ans[N],bl[N];
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&b,&a);
    bl[1]=a;
    if(b==1)
    {
        if(a!=n)
        {
            puts("-1");
            return 0;
        }
        for(int i=1; i<=n; i++)
            printf("%d ",n-i+1);
        puts("");
        return 0;
    }
    int te=(n-a)/(b-1);
    for(int i=2; i<=b; i++)
        bl[i]=te;
    te=(n-a)%(b-1);
    for(int i=2; te&&i<=b; te--,i++)
        bl[i]++;

    for(int i=1; i<=b; i++)
    {
        if(bl[i]>a || !bl[i])
        {
            puts("-1");
            return 0;
        }
    }
    int now=0;
    for(int i=1; i<=b; i++)
    {
//            printf("\n%d+++\n",bl[i]);
        te=now+bl[i];
        for(int j=1; j<=bl[i]; j++)
            printf("%d ",te--);
        now+=bl[i];
    }
    return 0;
}
/********************

********************/
