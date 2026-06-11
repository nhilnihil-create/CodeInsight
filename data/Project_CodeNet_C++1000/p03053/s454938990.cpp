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
    ll H, W;
    cin >> H >> W;
    vector<string> A(H+2);
    A[0] = string(W+2, '#');
    A[H+1] = string(W+2, '#');
    REP(i,1,H+1) {
        string a;
        cin >> a;
        A[i] = "#" + a + "#";
    }
    
    mat D(H+2, vec(W+2, INF));
    queue<pll> Q;
    REP(i,0,H+2) {
        REP(j,0,W+2) {
            if(A[i][j] == '#') {
                D[i][j] = 0;
                if(!(i == 0 || i == H+1 || j == 0 || j == W+1)) Q.push({i, j});
            }
        }
    }

    vector<pll> DIR = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while(!Q.empty()) {
        pll v = Q.front(); Q.pop();
        FORR(d,DIR) {
            ll i = v.first + d.first, j = v.second + d.second;
            if(D[i][j] >= INF) {
                D[i][j] = MIN(D[i][j],D[v.first][v.second]+1);
                Q.push({i, j});
            }
        }
    }

    ll m = 0;
    REP(i,0,H+2) {
        REP(j,0,W+2) m = MAX(m,D[i][j]);
    }
    PR(m);


    return 0;
}

/*



*/