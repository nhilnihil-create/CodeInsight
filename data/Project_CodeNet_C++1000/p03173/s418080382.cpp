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

const li N=405;

li dp[N][N];

void solve()
{
    li n;

    cin>>n;

    li a[n];

    vi sum(n);

    f(i,0,n-1)
    {
        cin>>a[i];

        sum[i]=(i>0?sum[i-1]:0)+a[i];
    }

    fr(l,n-1,0)
    {
        f(r,l,n-1)
        {
            if(l==r)
            {
                dp[l][r]=0;
            }
            else
            {
                dp[l][r]=1e18;

                f(i,l,r-1)
                {
                    dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+sum[r]-(l>0?sum[l-1]:0ll));
                }
            }
        }
    }

    cout<<dp[0][n-1];
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