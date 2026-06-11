#include <bits/stdc++.h>
#define rep(i, start, end) for (long long i = start; i < end; ++i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((long long)(x).size())
#define srt(x) sort((x).begin(), (x).end())
#define rsrt(x) sort((x).rbegin(), (x).rend())
#define g(a, b) __gcd((a), (b))
#define l(a, b) ((a) / __gcd((a), (b)) * (b))
using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;
using vllvll = vector<vll>;
using vc = vector<char>;
using vs = vector<string>;
using um = unordered_map<long long, long long>;
template<class T>void print(T x) { cout << '\n' << "== " << x << " ==" << '\n'; }
template<class T>void print1d(T x,ll n=-1){if(n==-1)n=x.size();rep(i,0,n){cout<<x[i]<<' ';}cout<<'\n';}
template<class T>void print2d(T x,ll r=-1,ll c=-1){if(r==-1)r=x.size();if(c==-1)c=x[0].size();rep(i,0,r)print1d(x[i],c);}
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
template<class T, class U>T rem(T a, U b) { return a - b*floor(a/b); }
template<class T>ld deg2rad(T deg) { return M_PI * deg / 180.0; }
template<class T>ld rad2deg(T rad) { return 180.0 * rad / M_PI; }
const long double pi = M_PI;
const long double doublepi = M_PI * 2.0;
const long double halfpi = M_PI / 2.0;
const long long big = 1LL << 50;
const long long inf = 1LL << 60;
const long long MOD = 1e9 + 7;


struct Edge
{
        ll to;
        ll cost;
};

ll MAX = 200010;
vector<vector<Edge> > Mat(MAX);
vll seen(MAX, 0);
set<ll> ans;
set<ll> ans2;

void rec(ll node, ll length)
{
        //cout << "node: " << node << " length: " << length << endl;
    seen[node] = 1;
    if (length % 2 == 0) {
            ans.insert(node);
    } else {
            ans2.insert(node);
    }

        //cout << "len "  << len(Mat[node]) << endl;
    for (auto adj : Mat[node]) {
        if (seen[adj.to] == 1) continue;
        rec(adj.to, length+adj.cost);
    }
}

void dfs(ll start)
{
    fill(seen.begin(), seen.end(), 0);
    rec(start, 0);
}

int main()
{
    ll N;
    cin >> N;
    rep(i, 0, N-1) {
            ll u, v, w;
            cin >> u >> v >> w;
            Edge e;
            e.to = v;
            e.cost = w;
            Mat[u].push_back(e);
            e.to = u;
            Mat[v].push_back(e);
    }
    ans.insert(1);
    dfs(1);

    vll ansset(all(ans));
    vll ansset2(all(ans2));

    vll tmp(N+1, 0);
    rep(i, 0, len(ans)) {
            tmp[ansset[i]] = 1;
    }

    rep(i, 1, N+1) {
            cout << tmp[i] << endl;
    }

    //print1d(ansset);
    //print1d(ansset2);
}

