#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
const int maxn=2e5+5;
int h[maxn];
ll a[maxn];
struct node
{
    int l,r;
    ll maxx;
}tree[4*maxn];
void build(int l,int r,int cur)
{
    tree[cur].l=l;
    tree[cur].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,cur<<1);
    build(mid+1,r,cur<<1|1);
    return;
}
void push_up(int cur)
{
    tree[cur].maxx=max(tree[cur<<1].maxx,tree[cur<<1|1].maxx);
    return;
}
void add(int pos,ll val,int cur)
{
    if(tree[cur].l==pos&&tree[cur].r==pos)
    {
        tree[cur].maxx=val;
        return;
    }
    if(tree[cur].l>pos||tree[cur].r<pos)
        return;
    add(pos,val,cur<<1);
    add(pos,val,cur<<1|1);
    push_up(cur);
    return;
}
ll query(int l,int r,int cur)
{
    if(tree[cur].l>=l&&tree[cur].r<=r)
        return tree[cur].maxx;
    if(tree[cur].l>r||tree[cur].r<l)
        return (ll)0;
    return max(query(l,r,cur<<1),query(l,r,cur<<1|1));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(0,n,1);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll cur=query(0,h[i]-1,1)+a[i];
        ans=max(ans,cur);
        add(h[i],cur,1);
    }
    printf("%lld\n",ans);
    return 0;
}
