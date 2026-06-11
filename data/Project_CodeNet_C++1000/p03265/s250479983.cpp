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


void solve(std::vector<long long> x, std::vector<long long> y){
    int x3 = x[1] - (y[1] - y[0]);
    int y3 = y[1] + (x[1] - x[0]);
    int x4 = x[0] - (y[1] - y[0]);
    int y4 = y[0] + (x[1] - x[0]);
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}

int main(){
    std::vector<long long> x(2);
    std::vector<long long> y(2);
    for(int i = 0 ; i < 2 ; i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&y[i]);
    }
    solve(std::move(x), std::move(y));
    return 0;
}

