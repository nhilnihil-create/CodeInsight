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

const int mod = 1e9+7;

void add_self(int &a, int b){
    a+=b;
    if (a>=mod) {
        a-=mod;
    }
}

vector<ll> dp;
vector<ll> pre;

void rec(int i, const vector<int> &not_taken, ll score_so_far, int mask, int group){
    if (i == (int) not_taken.size()) {
        dp[mask] = max(score_so_far + pre[group], dp[mask]);
        return;
    }
    rec(i+1, not_taken, score_so_far, mask, group);
    rec(i+1, not_taken, score_so_far, mask|(1<<not_taken[i]), group | (1<<not_taken[i]));
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    pre.resize(1<<n);
    for (int mask = 0; mask < (1<<n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1<<i)) {
                for (int j = i+1; j < n; ++j) {
                    if (mask & (1<<j)) {
                        pre[mask] += a[i][j]; 
                    }
                }
            }
        }
    }
    dbg(pre);

    ll INF = 1e18 + 123;;
    dp.resize(1 << n, -INF);
    dp[0]=0;
    for (int mask = 0; mask < (1<<n); ++mask) {
        vector<int> not_taken;
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1<<i))) {
                not_taken.push_back(i);
            }
        }
        rec(0, not_taken, dp[mask], mask, 0);
    }

    
    dbg(dp);
    cout << dp[(1<<n)-1] << endl;


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

