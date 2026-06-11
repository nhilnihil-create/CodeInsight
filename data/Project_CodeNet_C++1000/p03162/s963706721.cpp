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
const int Max=1e5+8;
const int OO=-1e6;
int xt[4]= {1,0,0,-1};
int yt[4]= {0,1,-1,0};
////////////////////////////////////////////////////////////////////////////////////

ll mem[100005][5],a[100005],b[100005],c[100005],n,m;
bool valid(int x,int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
void init()
{
    memset(mem,-1,sizeof mem);
}
/////////////////////////////////////////////////////////////////////
ll solve(int i=0, int k=3)
{
    if(i==n)
        return 0;
    ll &ret=mem[i][k];
    if(~ret)return ret;
    ret =0;
    if(k!=0)
        ret=max(ret,solve(i+1,0)+a[i]);

    if(k!=1)
        ret=max(ret,solve(i+1,1)+b[i]);
    if(k!=2)
        ret=max(ret,solve(i+1,2)+c[i]);
    return ret;
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
            cin >> a[i] >> b[i]>>c[i];
        }
        cout << solve();
    }
}
