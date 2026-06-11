#include <bits/stdc++.h>
using namespace std;

#define mem(a,n) memset(a,n,sizeof(a))
#define memc(a,b) memcpy(a,b,sizeof(b))
#define rep(i,a,n) for(int i=a;i<n;i++) ///[a,n)
#define pb push_back
#define IO ios::sync_with_stdio(false)
#define fre freopen("in.txt","r",stdin)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
typedef unsigned long long ull;
const double PI=acos(-1.0);
const double E=2.718281828459045;
const double eps=1e-8;
const int INF=0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int MOD=1e3;
const int N=1e5+5;
const ll maxn=1e6+5;
const int dir[4][2]= {-1,0,1,0,0,-1,0,1};

ll n,a,b;
void solve()
{
    if(a+b>n+1||a*b<n)///第一个条件很容易知道 第二个条件就写写找找看吧。。
    {
        cout<<-1;
        return ;
    }
    while(n>0)///每轮都是构造一个递增的子序列
    {
        ll x=min(a,n-b+1);///每一轮都取递增数和递减数中较小的那个
        //cout<<"x="<<x<<endl;
        for(ll i=n-x+1;i<=n;i++)
            cout<<i<<" ";
        n-=x;///x 为这一轮构造的递增子序列的个数
        b--;///递减的值 b 每一轮 -1
    }
}
int main()
{
    while(cin>>n>>a>>b)
    {
        solve();
        cout<<endl;
    }
    return 0;
}
