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
    li n,k;

    cin>>n>>k;

    li a[n];

    vi dp(k+1);

    dp[0]=1;

    f(i,0,n-1)
    {
        cin>>a[i];

        vi cum(k+1);      // cumulative

        fr(used,k,0)
        {
            li val=dp[used];

            li l=used+1;
            li r=used+min(a[i],k-used);

            if(l<=r)
            {
                cum[l]+=val;
                cum[l]%=M;

                if(r+1<=k)
                {
                    cum[r+1]-=val;
                    cum[r+1]+=M;
                    cum[r+1]%=M;
                }
            }
        }

        li sum=0;

        f(j,0,k)
        {
            sum+=cum[j];
            sum%=M;
            dp[j]+=sum;
            dp[j]%=M;
        }
    }

    cout<<dp[k];
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