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

char aChar = '.';
char bChar = '#';

void solve(long long A, long long B){
    if(A==1 && B ==1){
        cout << "1 2" << endl;
        cout << ".#" << endl;
        return;
    }
    if(B < A) {
        char tmp  = aChar;
        aChar = bChar;
        bChar = tmp;
        LL tmp2 = A;
        A = B;
        B = tmp2;
    }

    A--;
    if(A == 0) B++;
    vector<string> ans;
    while (B != 1) { 
        string tmp = "";
        REP(i, 100) {
            if(i % 2 == 0 && B != 1) {
                tmp += bChar;
                B--;
            } else {
                tmp += aChar;
            }
        }

        string tmp2(100, aChar);
        ans.PB(tmp);
        ans.PB(tmp2);
    }
    
    while (A != 0) { 
        string tmp = "";
        REP(i, 100) {
            if(i % 2 == 0 && A != 0) {
                tmp += aChar;
                A--;
            } else {
                tmp += bChar;
            }
        }

        string tmp2(100, bChar);
        ans.PB(tmp2);
        ans.PB(tmp);
        
    }

    cout << ans.size() << " 100" << endl;
    REP(i, ans.size()) {
        cout << ans[i] << endl;
    }
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}
