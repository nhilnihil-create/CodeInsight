#include <bits/stdc++.h>
#define f first
#define s second
#define MOD 1000000007
#define PMOD 998244353
#define pb(x) push_back(x)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> plii;
typedef pair<int, pii> piii;
const int INF = 1e9+10;
const ll LINF = 1LL*INF*INF;
const int MAXN = 3e5+10;
const int MAXM = 5e3+10;

priority_queue<int> pq;
vector<vector<int> > graph;
queue<int> que;

ll fac[MAXN];
ll inver[MAXN];

ll mypow(ll n,ll m)
{
    ll res = 1;
    while(m){
        if(m&1)res = (res*n)%PMOD;
        n = (n*n)%PMOD;
        m>>=1;
    }
    return res;
}

ll ncr(ll n,ll m)
{
    ll res = fac[n];
    res*=inver[m];
    res%=PMOD;
    res*=inver[n-m];
    res%=PMOD;
    return res;
}

int main()
{
    ll n,m,k,a,b,x,y,q;
    int sum = 0;
    int cnt = 0;
    int mx = 0;
    int mn = INF;
    int cur = 0, idx = -1;
    int tc;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>a>>b>>k;

    fac[0] = 1;

    for(ll i=1;i<=n;i++)fac[i] = (i*fac[i-1])%PMOD;

    inver[n] = mypow(fac[n],PMOD-2);

    for(ll i=n-1;i>=0;i--)
        inver[i] = (inver[i+1]*(i+1))%PMOD;

    ll j;

    ll res = 0;

    for(ll i=0;i<=n;i++){
        if(a*i>k)break;
        if(!((k-a*i)%b)){
            j = (k-a*i)/b;
            if(j>n)continue;
            x = ncr(n,i);
            y = ncr(n,j);
            res+=(x*y)%PMOD;
            res%=PMOD;
        }
    }

    cout<<res<<"\n";

    return 0;
}
