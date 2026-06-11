#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<long long,long long> pll;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define int long long
#define sz(v) (int)v.size()
#define inf 2147483647
#define llinf 9223372036854775807
#define all(v) v.begin(),v.end()
#define bp(n) __builtin_popcountll(n)
#define f(i,l,r) for(long long i=l;i<=r;i++)
#define rf(i,r,l) for(long long i=r;i>=l;i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }


const int N=3e3+5,mod=1e9+7,bit=61;

int n;
ld dp[N][N];
ld p[N];

ld solve(int x,int heads)
{
    if( (heads<<1) >=(n+1))
    {
        return 1.0;
    }
    if(x==n+1)
    {
        return 0.0;
    }
    ld &ans=dp[x][heads];
    if(ans!=-1.0)
    {
        return ans;
    }
    ans = p[x]*solve(x+1,heads+1)+(1.0-p[x])*solve(x+1,heads);
    return ans;
}

signed main()
{
    fast;

    int t=1;
    //cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j]=-1.00;
        cout<<fixed<<setprecision(10)<<solve(1,0)<<endl;
    }
    return 0;
}
