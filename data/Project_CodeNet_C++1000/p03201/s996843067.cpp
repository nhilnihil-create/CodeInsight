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

int A[200000];
vi poss,num;
int pp[200000];
vi adjList[200000];
int visited[200000],parent[200000],depth[200000];
vpii vv;
int doDFS(int u,int p,int d) {
    int i;
    visited[u] = 1,parent[u] = p,depth[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    return 0;
}
int main() {
    int i;
    int N;
    scanf("%d",&N);
    for (i = 0; i < N; i++) scanf("%d",&A[i]),poss.pb(A[i]);
    sort(poss.begin(),poss.end());
    poss.resize(unique(poss.begin(),poss.end())-poss.begin());

    int ans = 0;
    num.resize(poss.size());
    for (i = 0; i < N; i++) num[lower_bound(poss.begin(),poss.end(),A[i])-poss.begin()]++;
    for (i = 0; i < poss.size(); i++) {
        int b = 0;
        while ((1 << b) <= poss[i]) b++;
        int z = (1 << b)-poss[i];
        int p = lower_bound(poss.begin(),poss.end(),z)-poss.begin();
        if ((p != poss.size()) && (poss[p] == z)) {
            if (i != p) adjList[i].pb(p),adjList[p].pb(i);
            else pp[i] = 1;
        }
    }
    for (i = 0; i < poss.size(); i++) {
        if (!visited[i]) doDFS(i,-1,0);
    }
    for (i = 0; i < poss.size(); i++) vv.pb(mp(depth[i],i));
    sort(vv.begin(),vv.end());
    for (i = (int) vv.size()-1; i >= 0; i--) {
        int u = vv[i].second;
        if (parent[u] != -1) {
            int x = min(num[u],num[parent[u]]);
            ans += x,num[u] -= x,num[parent[u]] -= x;
        }
        else if (pp[u]) ans += num[u]/2;
    }
    printf("%d\n",ans);

    return 0;
}

