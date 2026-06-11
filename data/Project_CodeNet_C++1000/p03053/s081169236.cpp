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
    A[H+1] = string(W+2, '$');
    REP(i,1,H+1) {
        string s;
        cin >> s;
        A[i] = "#" + s + "#";
    }

    queue<pll> Q;
    mat D(H+2, vec(W+2, -1));
    REP(i,1,H+1) {
        REP(j,1,W+1) {
            if(A[i][j] == '#') {
                Q.push({i, j});
                D[i][j] = 0;
            }
        }
    }

    vector<pll> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while(!Q.empty()) {
        pll p = Q.front(); Q.pop();
        ll i = p.first, j = p.second;
        FORR(d,dir) {
            ll k = i + d.first, l = j + d.second;
            if(A[k][l] == '.' && D[k][l] == -1) {
                D[k][l] = D[i][j] + 1;
                Q.push({k, l});
            }
        }
    }

    ll m = 0;
    REP(i,1,H+1) {
        REP(j,1,W+1) {
            m = MAX(m,D[i][j]);
        }
    }
    PR(m);

    return 0;
}

/*



*/