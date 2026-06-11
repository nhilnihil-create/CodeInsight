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

int dp[100001];

void solve(long long N){
    REP(i, 100001) dp[i] = INF;
    dp[0] = 0;
    VI memo;
    memo.PB(1);
    LL tmp = 6;
    memo.PB(tmp);
    while(tmp * 6 <= 100000) {
        tmp *= 6;
        memo.PB(tmp);
    }
    tmp = 9;
    memo.PB(tmp);
    while(tmp * 9 <= 100000) {
        tmp *= 9;
        memo.PB(tmp);
    }
    sort(ALL(memo));

    REP(i, 100000) {
        REP(j, memo.size()) {
            int next = i + memo[j];
            if(next <= 100000) {
                dp[next] = min(dp[next], dp[i] + 1);
            }
        }
    }

    cout << dp[N] << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    solve(N);
    return 0;
}
