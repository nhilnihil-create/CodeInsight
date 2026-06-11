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

int main()
{
    vec A(3);
    cin >> A[0] >> A[1] >> A[2];
    ASC(A);

    ll b = (A[2]-A[0])/2;
    ll c = (A[2]-A[1])/2;
    A[0] += b*2;
    A[1] += c*2;
    ASC(A);
    A[1] -= A[0];
    A[2] -= A[0];
    A[0] = 0;
    ll ans = b + c;
    if(A[0]%2+A[1]%2+A[2]%2 == 1) ans += 1;
    else if(A[0]%2+A[1]%2+A[2]%2 == 2) ans += 2;
    PR(ans);

    return 0;
}

/*



*/