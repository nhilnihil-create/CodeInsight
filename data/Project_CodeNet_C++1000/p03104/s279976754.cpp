#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

ll lllog2(ll n)
{
    ll c = 0;
    while(n > 1) {
        n /= 2;
        ++c;
    }
    return c;
}

ll xorsum(ll n)
{
    if(n <= 0) return 0;
    else if(n == 1) return 1;
    else if(n == 2) return 3;
    else {
        ll l = lllog2(n + 1);
        ll m = n - (1LL << l);
        if((m + 2) % 2 == 1) return xorsum(m);
        else return (xorsum(m) ^ (1LL << l));
    }
}

int main()
{
    ll A, B;
    cin >> A >> B;

    PR(xorsum(B)^xorsum(A-1));

    return 0;
}

/*



*/