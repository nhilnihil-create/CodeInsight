#include <bits/stdc++.h>
#include <tuple>
using namespace std;

#ifdef LOCAL 
string to_string(char a) { return string(1,a); }
string to_string(bool a) { return a ? "1" : "0"; }
string to_string(const char* a) { return (string)a; }
string to_string(string a) { return a; }
string to_string(vector<bool> v) {
	string s = "["; for(unsigned i=0;i<v.size();i++){ s += ((i>0)?" ":"");
    s += char('0'+v[i]); } 	s += "]"; return s; }
template<class A, class B> string to_string(pair<A,B> p);
template<class T> string to_string(T v) {
	bool b = 1; string s = "["; for (const auto& x: v) {
		if (!b) {s += ", ";} b = 0; s += to_string(x); } s += "]"; return s; }
template<class A, class B> string to_string(pair<A,B> p) {
	return "("+to_string(p.first)+", "+to_string(p.second)+")"; }
void dbgf() { cerr << endl; }
template<class H, class... T> void dbgf(H h, T... t) {
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	dbgf(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << " = ", dbgf(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
#define boolout(x) cout<<(x?"YES":"NO")<<endl;
typedef long long ll;

vector<vector<int>> g;
int mod = 1e9+7;

ll mul(ll a, ll b){
    return (ll) a*b%mod;
}

pair<ll, ll> dfs(ll v, ll p){
    ll w = 1, b = 1;
    for (ll to : g[v]) {
        if (to!=p) {
            pair<ll, ll> temp = dfs(to, v);
            w = mul(w, (temp.first + temp.second)%mod);
            b = mul(b, temp.first);
        }
    }
    pair<ll, ll> res = {w, b};
    //dbg(v, res);
    return res;
}

void solve()
{
    int n;
    cin >> n;
    g = vector<vector<int>>(n);
    for (int i = 0; i < n-1; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--;t2--;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }

    pair<ll, ll> res = dfs(0, -1);
    ll ans = (res.first + res.second) % mod;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}

