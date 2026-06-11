#include<bits/stdc++.h>
#define lson root<<1
#define rson root<<1|1
using namespace std;
 
int n;
int a[200010];
int sum[200010];
 
struct node
{
    int l,r,sum;
}tr[1600080];
 
int push_up(int root)
{
    tr[root].sum=tr[lson].sum+tr[rson].sum;
}
 
int build(int root,int l,int r)
{
    if(l==r)
    {
        tr[root].sum=0;
        tr[root].l=l;
        tr[root].r=r;
        return 0;
    }
    tr[root].l=l;
    tr[root].r=r;
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(root);
}
 
int update(int root,int pos)
{
    if(pos==tr[root].l&&pos==tr[root].r)
    {
        tr[root].sum++;
        return 0;
    }
    int mid=(tr[root].l+tr[root].r)>>1;
    if(pos<=mid)
    {
        update(lson,pos);
    }
    else
    {
        update(rson,pos);
    }
    push_up(root);
}
 
int query(int root,int l,int r)
{
    if(l>r) return 0;
    if(l<=tr[root].l&&tr[root].r<=r) return tr[root].sum;
    int mid=(tr[root].l+tr[root].r)>>1;
    if(r<=mid)
    {
        return query(lson,l,r);
    }
    else
    {
        if(l>mid)
        {
            return query(rson,l,r);
        }
        else
        {
            return query(lson,l,mid)+query(rson,mid+1,r);
        }
    }
}
 
int check(int x)
{
    long long ans=0;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+((a[i]<=x)?1:-1);
    }
    for(int i=0;i<=n;i++)
    {
        sum[i]+=n+1;
    }
    build(1,1,200010);
    for(int i=0;i<=n;i++)
    {
        ans+=query(1,1,sum[i]-1);
        update(1,sum[i]);
    }
    return ans>=1ll*n*(n+1)/4+1;
}
 
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int l=1,r=1e9,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
        if(r-l<=1) 
        {
            mid=check(l)?l:r;
            break;
        }
    }
    printf("%d\n",mid);
}