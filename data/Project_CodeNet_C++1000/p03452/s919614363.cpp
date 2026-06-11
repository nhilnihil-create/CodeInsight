#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
//const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

class UF
{
private:
    int         num;
    vector<int> par;
    vector<int> siz;
    vector<ll>  wt;   // diff from par
public:
    vector<ll> parval;   // val of root
public:
    UF(int n): num(n) {
        par.resize(n);
        siz.resize(n);
        wt.resize(n);
        parval.resize(n);
        int i;
        for(i=0; i<n; i++) {
            par[i]=i; siz[i]=1;
            wt[i]=0;
            parval[i]=0;
        }
    }
	
    int find(int x) {
        int p=par[x];
        if(x==p) {
            return x;
        }
        int q=find(p);
        ll diff=wt[q]-wt[p];
        wt[x]-=diff;
        return par[x]=q;
    }

    bool unite(int x, int y, ll diff) {     // val[y]=val[x]+diff
        int px=find(x);
        int py=find(y);
        ll diff0=wt[y]-wt[x];
        diff-=diff0;

        x=find(x);
        y=find(y);
        if(x==y) {
            return (wt[y]==wt[x]+diff);
        }
        if(siz[x]<siz[y]) {
            par[x]=y;
            siz[y]=siz[x]+siz[y];
            //val[y]=val[x]+val[y];
            wt[x]=-diff;
        }
        else {
            par[y]=x;
            siz[x]=siz[x]+siz[y];
            //val[x]=val[x]+val[y];
            wt[y]=diff;
        }
        return true;
    }

    bool same(int x, int y) {
        return find(x)==find(y);
    }

    int size(int x) {
        return siz[find(x)];
    }

    ll GetWt(int x) {
        int p=find(x);
        return wt[x];
    }

    int ngroup() {
    //int ngroup( int& ans ) {
        int count=0;
        int i;
        for(i=0; i<num; i++) {
            if(par[i]==i) {
                count++;
                //ans += (val[i]? siz[i]: siz[i]-1);
            }
        }
        return count;
    }

    void print() {
        int i;
        printf("par: "); for(i=0; i<num; i++) printf("%d ", par[i]); printf("\n");
        printf("wt:  "); for(i=0; i<num; i++) printf("%lld ", GetWt(i)); printf("\n");
    }
};

void solve()
{
    int n,m;
    scanf("%d%d", &n, &m);
    UF uf(n);
    int i;
    int cnt=0;
    for(i=0; i<m; i++) {
        int l,r,d;
        scanf("%d%d%d", &l, &r, &d); l--; r--;
        bool ok=uf.unite(l,r,d);
        if(ok) {
            cnt++;
        }
    }
    if(cnt==m) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
