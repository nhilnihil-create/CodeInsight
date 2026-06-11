#include <bits/stdc++.h>
#define eps 1e-3
#define pi acos(-1.0)
#define inf 0x3f
#define INF 0x3f3f3f3f
#define pb push_back
#define debug1 cout<<"&&";
#define debug2 cout<<"**";
#define ms(a, x) memset(a, x, sizeof(a))
#define for0(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;
const int mod = 1e9 + 7;
const int N = 2e5+10;
const int M = 1e6+10;
/*=================================================================================*/
#define mid ((l+r)>>1)

struct node {
    int id,h;
    ll s;
}arr[N];
ll dp[N],maxx[N<<2];
void up(int rt) {
    maxx[rt] = max(maxx[rt<<1],maxx[rt<<1|1]);
}
void update(int rt,int l,int r,int x,ll v)
{
    if(l==r)
    {
        maxx[rt] = max(maxx[rt],v);
        return ;
    }
    if(x<=mid) update(rt<<1,l,mid,x,v);
    else update(rt<<1|1,mid+1,r,x,v);
    up(rt);
}
ll query(int rt,int l,int r,int x,int y)
{
    if(x>r||y<l) return 0;
    if(x<=l&&r<=y)
    {
        return maxx[rt];
    }
    if(x>mid) return query(rt<<1|1,mid+1,r,x,y);
    else if(y<=mid) return query(rt<<1,l,mid,x,y);
    else return max(query(rt<<1,l,mid,x,y),query(rt<<1|1,mid+1,r,x,y));
}
int main() {
    int n;
    ll ans = 0;
    scanf("%d", &n);
    for(int i = 1;i<=n;++i) scanf("%d",&arr[i].h);
    for(int i = 1;i<=n;++i) scanf("%lld",&arr[i].s),arr[i].id = i;
    for(int i = 1;i<=n;++i)
    {
        ll tmp = 0;
        if(arr[i].h>1)  tmp = query(1,1,n,1,arr[i].h-1);
        update(1,1,n,arr[i].h,tmp+arr[i].s);
    }
    printf("%lld\n",maxx[1]);
    return 0;
}