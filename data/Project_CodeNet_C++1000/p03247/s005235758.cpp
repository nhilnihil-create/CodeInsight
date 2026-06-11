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

int n,x,y,l;
vpi pos;
vi lens,d;
map<int,int> tempd;

const char vec[4] = {'L', 'D', 'U', 'R'};
signed main(){
    I(n);
    REP(i,n){
        I(x); I(y);
        pos.eb(x,y);
        lens.pb(abs(x) + abs(y));
        if (i && lens[i]%2 != lens[i-1]%2 ){
            cout << -1 << endl;
            return 0;
        }
    }
    int ld = 33;
    
    // REP(i,ld) d.pb(1LL << i);
    // if (lens[0]%2 == 0) d.pb(1);
    printf("%lld\n",ld + (lens[0]%2==0));
    REP(i,ld) printf("%lld ", 1LL<<i);
    if (lens[0]%2 == 0) printf("1");
    printf("\n");

    int dsum = (1LL << ld) - 1;


    for (auto p: pos){
        int px = p.first;
        int py = p.second - 1 + (lens[0]%2);
        
        int u = px + py;
        int v = px - py;
        int du = (u+dsum)/2;
        int dv = (v+dsum)/2;

        REP(i,ld){
            int mask = 1LL << i;
            printf("%c", vec[((mask&du)>0) * 2 + ((mask&dv)>0)]);
        }
        if (lens[0]%2 == 0) printf("U");
        printf("\n");

    }
}