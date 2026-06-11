#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head
const int nax = 1e5+2;
vi adj[nax];

void add(int& a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}
int mult(int a, int b) {
    return (ll) a * b % mod;
}
pair<int,int> dfs(int u, int p) {
    int allWhite = 1; // number of ways st every child is white
    int somethingBlack = 0; // means that something is black

    trav(v,adj[u]) {
        if(v != p) {
            pair<int,int> p = dfs(v,u);
            // from here, the number of ways to color the subtree of v such that v = black is first, means we need all to be white to color current node black
            somethingBlack = (mult(allWhite, p.first) + mult(somethingBlack, p.first + p.second)) % mod; // it means either child is white, or child is black
            allWhite = mult(allWhite, p.second); // # of ways st v is painted white
            // this is computing the complement of the options
            // this means like, either v is colored black (which means we multiply
            // allWhite * black is saying any of the ways that we computed right now * the number of ways to color this node black
            // otherwise we say that we multiply by the # of ways to color the subtree anyway assuming that we chose some node before to be colored black
        }
    } // no restriction on coloring white! B/c we can color a node white even when all children are white
    return mp(allWhite, (somethingBlack + allWhite) % mod);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    rep(i,0,n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    pair<int,int> p = dfs(1,-1);
    cout << (p.first + p.second) % mod;
    return 0;
}
