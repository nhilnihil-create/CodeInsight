//----------------------------templates
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("tune=native")
    #pragma GCC target ("avx")
    //----------------------------
    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    #define int ll

    #define FOR(i,j,n) for (int i=(int)(j);i<(n);i++)
    #define REP(i,n) for (int i=0;i<(int)(n);i++)
    #define REPS(i,n) for (int i=1;i<=(int)(n);i++)
    #define REPN(i,n) for (int i=(int)(n)-1;i>=0;i--)
    #define REPNS(i,n) for (int i=(int)(n);i>0;i--)

    #define I(n) scanf("%lld", &(n))
    #define LL(n) scanf("%lld", &(n))
    #define pb(n) push_back((n))
    #define mp(i,j) make_pair((i),(j))
    #define eb(i,j) emplace_back((i),(j))
    #define y0 y3487465
    #define y1 y8687969
    #define j0 j1347829
    #define j1 j234892
    #define uniq(v) v.erase( unique(v.begin(), v.end()), v.end() )

    #define all(x) (x).begin(),(x).end()
    #define sz(x) ((int)(x).size())

    typedef vector<int> vi;
    typedef pair<int,int> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;
    typedef vector<vpi> vvpi;
    typedef vector<vvi> vvvi;

    const int mod = 1000000007;

//--------------------------------------------
struct SegmentTree {
private:
    int n;
    vi node;

public:
    SegmentTree(vi v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        REP(i,sz) node[i+n-1] = v[i];
        REPN(i,n-2) node[i] = max(node[2*i+1], node[2*i+2]);
    }
    void update(int k, int x){
        k += n-1;
        node[k] = x;
        while(k){
            k = (k-1)/2;
            node[k] = max(node[2*k+1],node[2*k+2]);
        }
    }
    int getmax(int a, int b, int k=0, int l=0, int r=-1){
        if(r<0) r=n;
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b) return node[k];
        return max( getmax(a,b,2*k+1,l,(l+r)/2),getmax(a,b,2*k+2,(l+r)/2,r) );
    }
};


int n,c,x,v;
vpi sushi;
vi cl,ccl;

signed main(){
    I(n); I(c);
    sushi.resize(n);
    cl.resize(n);
    ccl.resize(n);

    REP(i,n){
        I(x); I(v);
        sushi[i] = mp(x,v);
    }

    int prev = 0;
    REP(i,n){
        cl[i] = sushi[i].second - (sushi[i].first - prev);
        prev = sushi[i].first;
    }
    prev = c;
    REP(i,n){
        ccl[i] = sushi[n-1-i].second - (prev - sushi[n-1-i].first);
        prev = sushi[n-1-i].first;
    }

    vi ruicl(n+1);
    FOR(i,1,n+1) ruicl[i] = ruicl[i-1] + cl[i-1];
    SegmentTree rc(ruicl);

    vi ruiccl(n+1);
    FOR(i,1,n+1) ruiccl[i] = ruiccl[i-1] + ccl[i-1];
    SegmentTree rcc(ruiccl);

    int ret = 0;
    REP(i,n+1) {
        ret = max(ret, ruicl[i] + max(0LL,rcc.getmax(0,n-i+1) - (i ? sushi[i-1].first : 0)));
    }
    REP(i,n+1) {
        ret = max(ret, ruiccl[i] + max(0LL,rc.getmax(0,n-i+1) - (i ? c - sushi[n-i].first : 0)));
    }
    cout << ret << endl;
}