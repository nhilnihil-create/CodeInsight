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
        node.resize(2*n-1, INT_MAX);
        REP(i,sz) node[i+n-1] = v[i];
        REPN(i,n-2) node[i] = min(node[2*i+1], node[2*i+2]);
    }
    void update(int k, int x){
        k += n-1;
        node[k] = x;
        while(k){
            k = (k-1)/2;
            node[k] = (node[2*k+1] + node[2*k+2]);
        }
    }
    int getsum(int a, int b, int k=0, int l=0, int r=-1){
        if(r<0) r=n;
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b) return node[k];
        return ( getsum(a,b,2*k+1,l,(l+r)/2) + getsum(a,b,2*k+2,(l+r)/2,r) );
    }
    int get(int k){
        return node[k+n-1];
    }

    void clear(){
        node = vi(2*n-1);
    }
};

int N;
vi a,b;
const int ofs = 100001;
SegmentTree st(vi(200010,0));


bool med(int cand){
    vi c(N+1);
    st.clear();

    FOR(i,1,N+1)
        c[i] = c[i-1] + (a[i-1] < cand ? -1 : 1); 

    int nat = 0;
    st.update(c[0]+ofs, st.get(c[0]+ofs)+1);
    FOR(i,1,N+1){
        nat += st.getsum(0,c[i]+ofs+1);
        st.update(c[i]+ofs, st.get(c[i]+ofs)+1);
    }
    cerr << nat << " " << (N*(N+1)/2)/2 <<  endl;
    return nat >= (N*(N+1)/2)/2;
}

signed main(){
    I(N);
    a.resize(N);
    REP(i,N) I(a[i]);

    b = a;
    sort(all(b));
    uniq(b);

    int lo = 0;
    int hi = sz(b);

    while(lo+1 < hi)
        if( med(b[(lo+hi)/2]) ){
            lo = (lo+hi)/2;
        } else {
            hi = (lo+hi)/2;
        }

    cout << b[lo] << endl;
}