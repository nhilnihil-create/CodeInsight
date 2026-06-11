/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

// ref: https://atcoder.jp/contests/abc116/submissions/13357105
// crux: pick max. "k" values and adjust for "cnt"

#define     int             long long int
#define     fast()          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)          begin(x),end(x)
#define     rz(x)           resize(x)
#define     asn(x,y)        assign(x,y)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)(x.size()))
#define     eb              emplace_back
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
#define     lcm(a,b)        ((a)*((b)/gcd((a),(b))))
#define     dbug(x)         cout<<#x<<": "<<(x)<<"\n"
#define     flush           fflush(stdout)
#define     show(x)         for(auto zz:x)cout<<zz<<" ";cout<<"\n";
#define     show2(x)        for(auto zz:x)cout<<zz.F<<" "<<zz.S<<"\n";

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ld pi=acos(-1);
const ll inf=1e18,M=1e9+7;
const int N=1;

void solve()
{
    int n,k;
    cin>>n>>k;

    vector<pii> v(n);
    for(int i=0;i<n;++i)
        cin>>v[i].S>>v[i].F;

    sort(all(v));                       // sorting in decreasing order
    reverse(all(v));

    priority_queue<int> pq;
    vi mark(n+1);

    int sum=0,cnt=0;
    for(int i=0;i<k;++i)                // picking max. "k" values (provides a base to work on)
    {
        if(mark[v[i].S])
            pq.push(-v[i].F);
        else
        {
            mark[v[i].S]=1;
            ++cnt;
        }

        sum+=v[i].F;
    }

    int ans=sum+cnt*cnt;
    for(int i=k;i<n;++i)                // increasing "cnt"...
    {
        if(cnt==k)
            break;

        if(mark[v[i].S])
            continue;

        mark[v[i].S]=1;

        int x=-pq.top();
        pq.pop();

        sum+=v[i].F-x,++cnt;
        ans=max(ans,sum+cnt*cnt);
    }

    cout<<ans;
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

