#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

int p[5002];
LLI num[5002][5002],dp[5002];
int x[5002][5002];
int main() {
    int i;
    int N,A,B;
    scanf("%d %d %d",&N,&A,&B);
    for (i = 1; i <= N; i++) scanf("%d",&p[i]);
    p[0] = 0,p[N+1] = N+1,N += 2;

    int j;
    for (i = 0; i < N; i++) {
        int c = 0;
        for (j = i; j < N; j++) {
            if (p[j] < p[i]) c++;
            num[i][j] += (LLI) B*c,x[i][j] += c;
        }
    }
    for (i = 0; i < N; i++) {
        int c = 0;
        for (j = i; j >= 0; j--) {
            if (p[j] > p[i]) c++;
            num[j][i] += (LLI) A*c,x[j][i] += c;
            if (x[j][i] != i-j-1) num[j][i] = 1e18;
        }
    }
    for (i = 0; i < N; i++) {
        dp[i] = num[0][i];
        for (j = 0; j < i; j++) {
            if (p[j] < p[i]) dp[i] = min(dp[i],dp[j]+num[j][i]);
        }
    }
    printf("%lld\n",dp[N-1]);

    return 0;
}

