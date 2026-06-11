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

const li M=1e9+7;

void solve()
{
    li n;

    cin>>n;

    li a[n][n];

    f(i,0,n-1)
    {
        f(j,0,n-1)
        {
            cin>>a[i][j];
        }
    }

    vi dp(1<<n);

    dp[0]=1;

    f(mask,0,(1<<n)-1)
    {
        li i=__builtin_popcount(mask);

        f(j,0,n-1)
        {
            if(a[i][j] && !(mask&(1<<j)))
            {
                dp[mask^(1<<j)]+=dp[mask];
                dp[mask^(1<<j)]%=M;
            }
        }
    }

    cout<<dp[(1<<n)-1];
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