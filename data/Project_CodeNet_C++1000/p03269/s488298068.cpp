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

int l;
vector<tuple<int,int,int>> edges;

signed main(){
    cin >> l;
    int nodes = 0;
    int li = l;
    while(li){
        nodes++;
        li /= 2;
    }
    REP(i,nodes-1){
        edges.emplace_back(i+1,i+2,0);
        edges.emplace_back(i+1,i+2,(1LL << i));
    }
    REPN(i,nodes-1){
        int mask = 1LL << i;
        if (mask & l){
            //cerr << i << endl;
            edges.emplace_back(i+1, nodes, (l >> (i+1)) << (i+1));
        }
    }
    cout << nodes << " " << edges.size() << endl;
    for (auto t: edges){
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    }
}