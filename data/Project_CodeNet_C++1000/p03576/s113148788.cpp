#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ALL(x)      (x).begin(),(x).end()
#define REP(i,n)    for(int i=0;i<(n);i++)
#define REP1(i,n)   for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n)   for(int i=(n);i>=0;i--)
#define CLR(a)      memset((a),0,sizeof(a))
#define MCLR(a)     memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};


void solve(long long N, long long K, std::vector<long long> x, std::vector<long long> y){
    vector<pair<LL, LL> > points;
    REP(i, N) points.PB({x[i], y[i]});

    sort(ALL(points));
    sort(ALL(x));
    sort(ALL(y));

    LL ans = INFL;
    REP(lx, N) REP2(rx, lx+1, N) REP(uy, N) REP(dy, N) {
        LL res = (x[rx]-x[lx]) * (y[dy]-y[uy]);
        if(ans <= res) continue;

        LL cnt = 0;
        REP(i, N) {
            if(x[lx] <= points[i].first && points[i].first <= x[rx] && y[uy] <= points[i].second && points[i].second <= y[dy]) {
                cnt++;
            }
        }

        if(K <= cnt) ans = min(ans, res);
    }

    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> x(N);
    std::vector<long long> y(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(N, K, std::move(x), std::move(y));
    return 0;
}
