#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define shalaby ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cerr.tie(0);
#define mod 100000000
using namespace std;

inline int D()
{
    int t;
    scanf("%d",&t);
    return t;
}
inline ll llD()
{
    ll t;
    scanf("%lld",&t);
    return t;
}
 ll Max=1e18+8;
const int OO=-1e6;
int xt[4]= {1,0,0,-1};
int yt[4]= {0,1,-1,0};
////////////////////////////////////////////////////////////////////////////////////

ll mem[100005],a[100005],n,m;
bool valid(int x,int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
void init()
{
    memset(mem,-1,sizeof mem);
}
/////////////////////////////////////////////////////////////////////
ll solve(int i=n-1)
{
    if(i<0)
        return Max;
        if(i==0)
            return 0;

    ll &ret=mem[i];
    if(~ret)return ret;
    return ret=min((solve(i-1)+abs(a[i]-a[i-1])),(solve(i-2)+abs(a[i]-a[i-2])));
}

int main()
{
    init();
    int T=1;
///   T=D();
    while(T-->0)
    {
        cin >> n ;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        cout << solve();
    }
}
