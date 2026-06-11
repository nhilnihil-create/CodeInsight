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


void solve(std::string S){
    bool flag = true;
    flag &= S[0] == 'A';
    flag &= ('a' <= S[1] && S[1] <= 'z');
    flag &= ('a' <= S[S.size()-1] && S[S.size()-1] <= 'z');

    bool flag2 = false;
    REP2(i, 2, S.size() - 1) {
        if(S[i] == 'C' && !flag2) {
            flag2 = true;
            continue;
        }

        flag &= ('a' <= S[i] && S[i] <= 'z');
    }

    cout << (flag && flag2 ? "AC" : "WA") << endl;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}

