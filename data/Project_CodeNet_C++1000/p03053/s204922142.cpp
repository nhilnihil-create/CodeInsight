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

int dx[4] = {-1,0,1,0},dy[4] = {0,-1,0,1};
char grid[1000][1000];
queue<pii> Q;
int dist[1000][1000];
int main() {
    int i,j;
    int H,W;
    scanf("%d %d",&H,&W);
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) scanf(" %c",&grid[i][j]);
    }

    int m = 0;
    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            dist[i][j] = -1;
            if (grid[i][j] == '#') dist[i][j] = 0,Q.push(mp(i,j));
        }
    }
    while (!Q.empty()) {
        int x = Q.front().second;
        int y = Q.front().first;
        Q.pop();

        m = max(m,dist[y][x]);
        for (i = 0; i < 4; i++) {
            int xx = x+dx[i],yy = y+dy[i];
            if ((xx >= 0) && (xx < W) && (yy >= 0) && (yy < H) && (dist[yy][xx] == -1)) {
                dist[yy][xx] = dist[y][x]+1;
                Q.push(mp(yy,xx));
            }
        }
    }
    printf("%d\n",m);

    return 0;
}

