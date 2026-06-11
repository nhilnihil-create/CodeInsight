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
    ll N;
    cin >> N;
    vector<string> S(N);
    REP(i,0,N) cin >> S[i];

    ll ab = 0, bxa = 0, xa = 0, bx = 0;
    REP(i,0,N) {
        ll M = SZ(S[i]);
        REP(j,0,M-1) {
            if(S[i][j] == 'A' && S[i][j+1] == 'B') ++ab;
        }
        if(S[i][0] == 'B' && S[i][M-1] == 'A') ++bxa;
        else if(S[i][0] == 'B' && S[i][M-1] != 'A') ++bx;
        else if(S[i][0] != 'B' && S[i][M-1] == 'A') ++xa;
    }

    if(xa > 0) {
        ab += bxa;
        --xa;
        ab += MIN(bx,xa+1);
    }
    else {
        if(bxa > 0) {
            ab += bxa-1;
            ab += MIN(bx,xa+1);
        }
        else {
            ab += MIN(xa,bx);
        }
    }

    PR(ab);


    return 0;
}

/*



*/