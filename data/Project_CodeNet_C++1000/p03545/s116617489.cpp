#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPD(i,N) for(int i=0; i<int(N); --i)
#define PB push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //配列の最大のrenge

int main() {
    string S;cin>>S;
    int a,b,c,d;
    a = S[0]-48;
    b = S[1]-48;
    c = S[2]-48;
    d = S[3]-48;
    int ope[2] = {-1,1};

    bool finish=false;
    REP(i,2){REP(j,2){REP(k,2) {
        int tmp = a + b*ope[i] + c*ope[j] + d*ope[k];
        if (tmp == 7) {
            //cout<<tmp<<i<<j<<k;
            char sa = (i==0 ? '-' : '+');
            char sb = (j==0 ? '-' : '+');
            char sc = (k==0 ? '-' : '+');
            printf("%d%c%d%c%d%c%d=7",a,sa,b,sb,c,sc,d);
            finish=true;
        }
        if(finish) break;
    }
    if(finish) break;
    }
    if(finish) break;
    }
}