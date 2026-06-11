#include<bits/stdc++.h>

using namespace std;

typedef long long int li;
typedef long double ld;
typedef vector<li> vi;
typedef pair<li,li> pi;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define B begin()
#define E end()
#define f(i,l,r) for(li i=l;i<=r;++i)
#define fr(i,l,r) for(li i=l;i>=r;--i)
#define u_map unordered_map
#define endl "\n"
#define debug(x) cout<<#x<<" = "<<x<<endl;

li fastpow(li base,li exp,li M) 
{
    li res=1;
    while(exp>0) {
        if(exp&1)
            res=(res*base)%M;

        base=(base*base)%M;
        exp>>=1;
    }
    return res;
}

const li N=1e5;
const li M=1e9+7;

vi graph[N];

// returns {subtree with black as root, subtree with white as root}

pi dfs(li u, li p)
{
    li all_white=1;
    li is_black=0;

    for(li v: graph[u])
    {
        if(v!=p)
        {
            pi tp=dfs(v,u);

            is_black = ((all_white*tp.F)%M + (is_black*(tp.F+tp.S))%M)%M;
            all_white = (all_white*tp.S)%M;
        }
    }

    return {all_white,(all_white+is_black)%M};
}

void solve()
{
    li n;

    cin>>n;

    f(i,0,n-2)
    {
        li u,v;

        cin>>u>>v;

        graph[u].PB(v);
        graph[v].PB(u);
    }

    pi tp = dfs(1,0);

    cout<<(tp.F+tp.S)%M;
}

int main()
{    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    li t=1;

    // cin>>t;

    while(t--)
    {
        solve();
    }

    return 0;
}