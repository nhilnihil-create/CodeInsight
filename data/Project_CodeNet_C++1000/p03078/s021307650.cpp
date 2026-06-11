/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

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
    int x,y,z,K;
    cin>>x>>y>>z>>K;

    vi a(x),b(y),c(z);
    for(int i=0;i<x;++i)
        cin>>a[i];
    for(int i=0;i<z;++i)
        cin>>b[i];
    for(int i=0;i<y;++i)
        cin>>c[i];

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    sort(c.rbegin(),c.rend());

    set<pair<int,array<int,3>>> st;
    st.ins({a[0]+b[0]+c[0],{0,0,0}});

    set<array<int,3>> vis;
    auto upd=[&st,a,b,c,x,y,z,K,&vis](array<int,3> arr)
    {
        if(arr[0]>=x || arr[1]>=y || arr[2]>=z || vis.find(arr)!=vis.end())
            return;

        vis.ins(arr);
        int sum=a[arr[0]]+b[arr[1]]+c[arr[2]];

        if(sz(st)==K)
        {
            int tmp=st.begin()->F;
            if(tmp<sum)
            {
                st.erase(st.begin());
                st.ins({sum,arr});
            }
        }
        else
            st.ins({sum,arr});
    };

    int sum;
    array<int,3> arr;
    while(!st.empty() && K--)
    {
        sum=st.rbegin()->F;
        arr=st.rbegin()->S;
        st.erase(--st.end());

        cout<<sum<<"\n";
        //show(arr);

        for(int i=0;i<3;++i)
        {
            ++arr[i];
            upd(arr);
            --arr[i];
        }
    }
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

