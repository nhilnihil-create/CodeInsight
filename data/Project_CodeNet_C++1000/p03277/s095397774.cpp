#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ld long double
#define mid (l+r)/2
typedef pair<int,int> pii;
const int maxn=100005;
int a[maxn],b[maxn],n;
int tr[2*maxn];
inline int lowbit(int x){return x&(-x);}
void add(int x,int y)
{
    for(int i=x;i<=2*n+1;i+=lowbit(i)) tr[i]+=y;
}
int sum(int x)
{
    int ret=0;
    for(int i=x;i>=1;i-=lowbit(i)) ret+=tr[i];
    return ret;
}
ll calc(int x)
{
    memset(tr,0,sizeof tr);
    ll ret=0;
    add(n+1,1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=x) b[i]=1;
        else b[i]=-1;
        b[i]+=b[i-1];
        ret+=sum(b[i]+n);
        add(b[i]+1+n,1);
    }
    return ret;
}
int main()
{
    #ifdef local
    freopen("in.txt","r",stdin);
    #endif
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll tot=1LL*(n+1)*n/2;
    int l=1,r=1e9,ans;
    while(l<=r)
    {
        if(calc(mid)>=tot/2+1)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
}
