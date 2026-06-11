#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define ind(a) scanf("%d", &a)
#define inlld(a) scanf("%lld", &a)
#define ind2(a, b) scanf("%d%d", &a, &b)
#define inlld2(a, b) scanf("%lld%lld", &a, &b)
#define ind3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define inlld3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

using namespace std;

const int N=8e3+5;
const int MOD=1e9+7;

typedef long long ll;
typedef long double ld;

char str[N];
ll n, x, y;
vector<ll>dx, dy;
bool dp[N][2*N], memo[N][2*N], memo2[N][2*N], dp2[N][2*N];

bool solve(ll i, ll j)
{
    if(i==dx.size())
        return j==x+N;
    if(memo[i][j])
        return dp[i][j];
    dp[i][j]=false;
    memo[i][j]=true;
    if(i>0)
        dp[i][j]|=solve(i+1, j-dx[i]);
    else if(str[0]=='T')
        dp[i][j]|=solve(i+1, j-dx[i]);
    dp[i][j]|=solve(i+1, j+dx[i]);
    // printf("%lld %lld\n", i, j);
    return dp[i][j];
}

ll solve2(ll i, ll j)
{
    if(i==dy.size())
        return j==y+N;
    if(memo2[i][j])
        return dp2[i][j];
    memo2[i][j]=true;
    dp2[i][j]=false;
    dp2[i][j]|=solve2(i+1, j+dy[i]);
    dp2[i][j]|=solve2(i+1, j-dy[i]);
    return dp2[i][j];
}

int main() 
{
    cin>>str>>x>>y;
    n=strlen(str);
    ll cnt=0, dir=0;
    for(ll a=0; a<n; a++)
    {
        if(str[a]=='T')
        {
            if(dir==0)
            {
                if(cnt>0)
                    dx.pb(cnt);
                cnt=0;
                dir=1;
            }
            else
            {
                if(cnt>0)
                    dy.pb(cnt);
                dir=0;
                cnt=0;
            }
        }
        else
            cnt++;
    }
    if(cnt>0)
    {
        if(dir)
            dy.pb(cnt);
        else
            dx.pb(cnt);
    }
    // for(ll a=0; a<dx.size(); a++)
    //     printf("%lld ", dx[a]);
    // printf("\n");
    // for(ll a=0; a<dy.size(); a++)
    //     printf("%lld ", dy[a]);
    // printf("\n");
    for(ll a=0; a<N; a++)
        for(ll b=0; b<2*N; b++)
        {
            memo[a][b]=false;
            memo2[a][b]=false;
        }
    bool ans=solve(0, N);
    ans&=solve2(0,N);
    if(ans)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

