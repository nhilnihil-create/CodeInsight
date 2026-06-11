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

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        vector<int> pref(i+1, 0);
        for (int j = 1; j < i; ++j) {
            pref[j] = (pref[j-1] + dp[i-1][j])%mod; 
        }
        for (int b = 1; b <= i; ++b) {
            int l, r;
            if (s[i-2]=='<') {
                l=1; r=b-1; 
            } else {
                l=b; r=i-1;
            }
            add_self(dp[i][b], (pref[r]-pref[l-1]+mod)%mod);
            /* for (int a = 0; a < b-1; ++a) { */
            /*     int real_a = a; */
            /*     if (b>=a) { */
            /*         real_a = a+1; */
            /*     } */
            /*     assert(real_a!=b); */
            /*     if ((real_a < b) != (s[i-2]=='<')) { */
            /*        continue; */
            /*     } */
            /*     add_self(dp[i][b], dp[i-1][a]); */
            /* } */
        }
    }
    dbg(dp);
    int res = 0;
    for (int i = 1; i < n+1; ++i) {
        add_self(res, dp[n][i]); 
    }
    cout << res << endl;
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

