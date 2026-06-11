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

int X[200000],Y[200000],s[200000];
set<pii> S;
int main() {
    int i;
    int H,W,N;
    scanf("%d %d %d",&H,&W,&N);
    for (i = 0; i < N; i++) scanf("%d %d",&X[i],&Y[i]),X[i]--,Y[i]--,S.insert(mp(Y[i],X[i]));

    int ans = 1e9,f = 0;
    s[0] = 0;
    for (i = 0; i < W; i++) S.insert(mp(i,H));
    for (i = 0; i < W; i++) {
        int x = s[i]+1;
        if (!S.count(mp(i,x))) {
            if (i < W-1) {
                while (S.count(mp(i+1,x))) {
                    if (S.count(mp(i,x+1))) {
                        f = 1;
                        break;
                    }
                    x++;
                }
                s[i+1] = x;
            }
        }
        else f = 1;
        auto it = S.lower_bound(mp(i,x));
        ans = min(ans,it->second);
        if (f) break;
    }
    printf("%d\n",ans);

    return 0;
}

