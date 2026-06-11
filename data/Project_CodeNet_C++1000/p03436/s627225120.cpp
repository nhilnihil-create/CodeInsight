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
    vector<string> S(H+2);
    S[0] = string(W+2, '#');
    S[H+1] = string(W+2, '#');
    REP(i,1,H+1) {
        string s;
        cin >> s;
        S[i] = "#" + s + "#";
    }

    mat D(H+2, vec(W+2, INF));
    queue<pll> Q;
    D[1][1] = 0;
    Q.push({1, 1});
    while(!Q.empty()) {
        pll v = Q.front(); Q.pop();
        REP(i,-1,2) {
            REP(j,-1,2) {
                if(i*j != 0 || (i == 0 && j == 0)) continue;
                ll h = v.first, w = v.second;
                if(S[h+i][w+j] == '.' && D[h+i][w+j] > D[h][w] + 1) {
                    D[h+i][w+j] = D[h][w] + 1;
                    Q.push({h+i, w+j});
                }
            }
        }
    }

    ll b = 1;
    REP(i,1,H+1) {
        REP(j,1,W+1) b += (S[i][j] == '#');
    }
    if(D[H][W] < INF) PR(H*W-b-D[H][W]);
    else PR(-1);

    return 0;
}

/*



*/