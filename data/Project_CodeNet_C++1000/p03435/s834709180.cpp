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
    mat c(3, vec(3));
    REP(i,0,3) REP(j,0,3) cin >> c[i][j];

    if(c[0][0]-c[0][1] == c[1][0]-c[1][1] && c[1][0]-c[1][1] == c[2][0]-c[2][1]
    && c[0][1]-c[0][2] == c[1][1]-c[1][2] && c[1][1]-c[1][2] == c[2][1]-c[2][2]
    && c[0][2]-c[0][0] == c[1][2]-c[1][0] && c[1][2]-c[1][0] == c[2][2]-c[2][0]) PR("Yes");
    else PR("No");    

    return 0;
}

/*



*/