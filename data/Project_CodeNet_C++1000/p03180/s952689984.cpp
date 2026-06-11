/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

// reference: https://codeforces.com/blog/entry/64250?#comment-482588

#include<bits/stdc++.h>
using namespace std;

#define     int             long long int
#define     fast()          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)          (x).begin(),(x).end()
#define     rz(x)           resize(x)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)(x.size()))
#define     pb              push_back
#define     pf              push_front
#define     pob             pop_back
#define     pof             pop_front
#define     ins             insert
#define     vi              vector<int>
#define     pii             pair<int,int>
#define     mii             map<int,int>
#define     F               first
#define     S               second
#define     makep           make_pair
#define     maket           make_tuple
#define     remax(a,b)      a=max(a,b)
#define     remin(a,b)      a=min(a,b)
#define     bitcount(x)     __builtin_popcountll(x)
#define     iceil(n,x)      (((n)+(x)-1)/(x))
#define     gcd(a,b)        (__gcd((a),(b)))
#define     lcm(a,b)        (((a)*(b))/gcd((a),(b)))
#define     dbug(x)         cout<<#x<<": "<<(x)<<"\n"
#define     flush           fflush(stdout)
#define     show(x)         for(auto zz:x)cout<<zz<<" ";cout<<"\n";
#define     show2(x)        for(auto zz:x)cout<<zz.F<<" "<<zz.S<<"\n";

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ld pi=acos(-1);
const ll inf=1e18,M=1e9+7;
const int N=17;

int mat[N][N];
vi tmp;

int calc(int mask)
{
    tmp.clear();
    for(int j=0;mask;mask>>=1,++j)
    {
        if(mask&1)
            tmp.pb(j);
    }

    int len=sz(tmp);
    int res=0;
    for(int i=0;i<len;++i)
    {
        for(int j=i+1;j<len;++j)
            res+=mat[tmp[i]][tmp[j]];
    }

    return res;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            cin>>mat[i][j];
    }

    int tot=(1<<n);
    int dp[tot],cost[tot];
    mem(dp,0);
    mem(cost,0);

    for(int mask=1;mask<tot;++mask)
        cost[mask]=calc(mask);

    for(int mask=1;mask<tot;++mask)
    {
        for(int sub=mask;sub;sub=(sub-1)&mask)
        {
            if(sub==mask)
                dp[mask]=cost[mask];
            else
                dp[mask]=max(dp[mask],dp[sub]+cost[mask^sub]);
        }
    }

    cout<<dp[(1<<n)-1];
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    for(int z=1;z<=t;++z)
    {
        solve();
        //cout<<"\n";
    }

    return 0;
}

