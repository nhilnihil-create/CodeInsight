#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.12f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define Endl endl
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

class UnionFind {
public:
    vector <ll> par;
    vector <ll> siz;


    UnionFind(ll N): par(N), siz(N, 1LL) {
        for (ll i = 0; i < N; ++i) par[i] = i;
    }

    void init(ll N) {
        par.resize(N);
        siz.assign(N, 1LL);
        for (ll i = 0; i < N; ++i) par[i] = i;
    }


    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }


    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool same(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    ll point = (ll)N*(N-1)/2;
    vector<ll> ans;
    UnionFind tree((ll)N);
    int A[100100],B[100100];
    rep(i,0,M){
        int a,b; cin >> a >> b;
        a--; b--;
        A[i] = a;
        B[i] = b;
    } 

    
    rep(i,0,M){
        ans.pb(point);
        if(tree.same(A[M-1-i], B[M-1-i])) continue;

        ll a = tree.size(A[M-1-i]);
        ll b = tree.size(B[M-1-i]);
        point -= a*b;
        tree.unite(A[M-1-i], B[M-1-i]);
    }
    reverse(all(ans));
    rep(i,0,SZ(ans)) cout << ans[i] << "\n";
    return 0;
}
