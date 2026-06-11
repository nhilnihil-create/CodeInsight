#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;
typedef priority_queue< int, vector< int >, greater< int > >  minHeap;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define mod 1000000007
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define bug(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << "\n"

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N = N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

inline int addmod(lli x,lli y)
{
    return (x%mod + y%mod)%mod;
}
inline int submod(lli x,lli y)
{
    return (x%mod - y%mod + mod)%mod;
}
inline int mulmod(lli x,lli y)
{
    return (x%mod * y%mod)%mod;
}


inline int nextSubMask(int i, int mask)
{
    return (i-1)&mask;   /// returns next  submask
}

template<typename T>
void we_r_done(T mssg)
{
    cout<<mssg;
    exit(0);
}


int main()
{
    ///freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    FastIO;

    string s;
    while(cin>>s){
        int n = s.size();
        lli dp[2][3] , tpow = 1;
        Fill(dp,0);
        int curr = 1;
        for(int i=0; i<n; i++){

            for(int j=0; j<3; j++) dp[curr][j] = dp[curr^1][j];

            if(s[i] == 'A') dp[curr][0] += tpow;
            if(s[i] == 'B') dp[curr][1] += dp[curr^1][0];
            if(s[i] == 'C') dp[curr][2] += dp[curr^1][1];

            if(s[i] == '?'){
                dp[curr][0] = (3*dp[curr^1][0] + tpow);
                dp[curr][1] = (3*dp[curr^1][1] + dp[curr^1][0]);
                dp[curr][2] = (3*dp[curr^1][2] + dp[curr^1][1]);
                tpow = mulmod(3,tpow);
            }
            for(int j=0; j<3; j++) dp[curr][j] %= mod;
            curr ^= 1;
        }
        cout<<dp[curr^1][2]<<endl;
    }

    return 0;
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
///using bs = bitset<MX>; // how many distinct number can be form?
///sort(atoz(v), [](const data x, const data y){return (x.a==y.a?x.b>y.b : x.a<y.a);});
