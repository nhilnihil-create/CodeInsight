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

const string YES = "Yes";
const string NO = "No";

void solve(long long H, long long W, std::vector<std::string> s){
    REP(i, H) {
        REP(j, W) {
            if(s[i][j] == '#') {
                bool flag = false;

                REP(m, 4) {
                    int mx = j+DX[m];
                    int my = i+DY[m];

                    if(RANGE(mx, my, W, H) && s[my][mx] == '#') {
                        flag = true;
                    }
                }

                if(!flag) {
                    cout << NO << endl;
                    return;
                }
            }
        }
    }

    cout << YES << endl;
}

int main(){
    long long H;
    scanf("%lld",&H);
    long long W;
    scanf("%lld",&W);
    std::vector<std::string> s(H);
    for(int i = 0 ; i < H ; i++){
        std::cin >> s[i];
    }
    solve(H, W, std::move(s));
    return 0;
}
