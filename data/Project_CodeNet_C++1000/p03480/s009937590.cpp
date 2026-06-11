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


void solve(string S){
    int m = S.length() / 2;
    int ans = m;
    char c = S[m];
    if(S.length() % 2 == 0) {
        if(c != S[m-1]) {
            cout << ans << endl;
            return;
        }

        ans++;
        int idx = 1;
        while(ans != S.length()) {
            if(S[m - idx - 1] != c || S[m + idx] != c) break;
            ans++;
            idx++;
        }
    } else {
        ans++;
        int idx = 1;
        while(ans != S.length()) {
            if(S[m - idx] != c || S[m + idx] != c) break;
            ans++;
            idx++;
        }
    }

    cout << ans << endl;
}

int main(){
    string S;
    cin >> S;
    solve(S);
    return 0;
}
