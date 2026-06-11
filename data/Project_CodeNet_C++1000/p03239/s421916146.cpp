#include <bits/stdc++.h>

using namespace std;
typedef long long               ll;
typedef long double             ld;

#define min3(a, b, c)           min((a), min((b), (c)))
#define max3(a, b, c)           max((a), max((b), (c)))
#define lcm(a,b)                (a / __gcd(a,b) ) *b
#define gcd(a,b)                __gcd(a,b)
#define dist(x1,y1,x2,y2)       sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define distl(x1,y1,x2,y2)      sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define sqr(a)                  ((a)*(a))
#define FOR(a, b)               for(int i=a; i<b; i++)
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen (x,"w",stdout)
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define lb                      lower_bound
#define ub                      upper_bound
#define all(a)                  a.begin(),a.end()
#define FASTIO                  ios_base::sync_with_stdio(0);cin.tie(NULL);
ll BMod(ll B,ll P,ll M)
{
    ll R=1;
    B=B%M;
    while(P)
    {
        if(P&1)
            R=(R*B)%M;
        P >>= 1;
        B=(B*B)%M;
    }
    return R;
}

ll invMOD(ll num,ll M)
{
    return BMod(num,M-2,M);
}


int main()
{
    FASTIO

    int n, k;
    vector<pair<int,int> > v;
    cin >> n >> k;

    FOR (0, n)
    {
        int x, y;
        cin >> x >> y;
        if (y <= k)
            v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    if (!v.empty())
        cout << v[0].ff;
    else
        cout << "TLE";
}