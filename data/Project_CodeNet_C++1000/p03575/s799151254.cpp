#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define srt(x) sort((x).begin(), (x).end());
#define rsrt(x) sort((x).rbegin(), (x).rend());
#define deb(x) cout<<#x<<" = "<<(x)<<" (L"<<LINE<<")"<<endl;
#define vdeb(x) {cout<<#x<<" = { "; rep(i, x.size()) cout<<x[i]<<' '; cout <<'}'<<" (L"<<LINE<<")"<<endl;}
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vivi = vector<vi>;
using vll = vector<long long>;
using vllvll = vector<vll>;
using vs = vector<string>;
using um = unordered_map<long long, long long>;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;

class UnionFind
{   
public:
    static const int N_MAX = 1000000;
    int par[N_MAX];
    int n;
    
    UnionFind(int n)
        : n{n}
    {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    void init()
    {
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }
    
    int root(int x)
    {
        if (par[x] == x) {
            return x;
        }
        return par[x] = root(par[x]);
    }
    
    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
    
    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) {
            return;
        }
        par[ry] = root(x);
        return;
    }
    
    int groups()
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (root(i) == i)
            ++cnt;
        }
        return cnt;
    }
};


int main()
{
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N+1);
    ll a, b;
    vll A(M), B(M);
    rep(i, 0, M) {
        cin >> a >> b;
        --a; --b;
        A[i] = a;
        B[i] = b;
    }  

    ll ans = 0;
    rep(i, 0, M) {
        uf.init();
        rep(j, 0, M) {
            if (i == j) continue;
            uf.unite(A[j], B[j]);
        }
        if (! uf.same(A[i], B[i])) {
            ++ans;
        }
    }

    cout << ans << endl;
}


/*
int main()
{
    ll N, M;
    cin >> N >> M;
    UnionFind uf(N);
    ll a, b;
    rep(i, 0, M) {
        cin >> a >> b;
        --a; --b;
        uf.unite(a, b);
    }
    rep(i, 0, N) {
        cout << uf.par[i] << endl;
    }
}
*/