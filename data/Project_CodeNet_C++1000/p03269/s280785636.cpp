#include<cstdio>
#include<cstring>
#include<algorithm>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
typedef long long ll;
int n,l;
int cnt;
struct node
{
    int u,v,val;
    node () {} node (int u1,int v1,int val1):u(u1),v(v1),val(val1) {}
} pr[70];
int main()
{
    SF("%d",&l);
    l--;
    int sum=1;
    int tot=0;
    for(tot=0; sum-1<=l&&tot<=19; tot++) sum*=2;
    sum/=2;
    for(int i=1; i<tot; i++)
    {
        pr[++cnt]=node(i,i+1,0);
        pr[++cnt]=node(i,i+1,1<<(i-1));
    }
    int pre=0;
    int tot1=tot;
    tot--;
    sum/=2;
    while(pre<l)
    {
        pre+=sum;
        for(; sum+pre+sum-1<=l; pre+=sum)
        {
            pr[++cnt]=node(tot,tot1,sum+pre);
        }
        sum/=2;
        tot--;
    }
    PF("%d %d\n",tot1,cnt);
    for(int i=1; i<=cnt; i++) PF("%d %d %d\n",pr[i].u,pr[i].v,pr[i].val);
}

