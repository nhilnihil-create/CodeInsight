/*
    I was lying to myself
*/




#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;

#define dbg          cout<<"Freak"<<endl;
#define dbgg(i)      cout<<i<<endl;
#define N            1e9+7
#define pb           push_back
#define pf           push_front
#define pi           acos(-1)
#define all(x)       x.begin(),x.end()
#define fast         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF          0x3f3f3f3f
#define inputfile    freopen("input.txt", "r", stdin)
#define outputfile   freopen("output.txt", "w", stdout)
#define appendfile   freopen("output.txt", "a", stdout)


struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1> {}(p.first);auto hash2 = hash<T2> {}(p.second);return hash1 ^ hash2;
    }
};

ll t;
ll mod=N;
ll BigMod(ll base,ll pow,ll mod)
{
    if(pow==0||base==1)return 1;
    else if(pow==1)return base;
    else if(pow%2)return BigMod(base,pow-1,mod)*base%mod;
    else {ll x=(BigMod(base,pow/2,mod)%mod);x=(x*x)%mod;return x;}
}



string s;
ll arr[1002][1002],dp[1002][1002];

ll solve(ll n,ll m)
{
    if(dp[n][m]!=-1)return dp[n][m];
    if(arr[n][m]==1)return 0;
    if(n==0||m==0)return 0;
    return dp[n][m]=(solve(n-1,m)+solve(n,m-1))%mod;
}


int main()
{
    //fast;
    ll a,b,c,d,e,f,g,i,j;
    ll n,m,k;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        for(j=0;j<m;j++)
        {
            if(s[j]=='#')arr[i][j+1]=1;
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[1][1]=1;
    cout<<solve(n,m)%mod<<endl;
    return 0;
}

