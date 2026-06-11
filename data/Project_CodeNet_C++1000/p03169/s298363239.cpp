#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define REP(i,x,y) for(ll i = x;i <= y;++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
vector<string> vec_splitter(string s) {
    for(char& c: s) c = c == ','?  ' ': c;
    stringstream ss; ss << s;
    vector<string> res;
    for(string z; ss >> z; res.push_back(z))
        ;
    return res;
}
void debug_out(vector<string> args, int idx) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, Head H, Tail... T) {
    if(idx > 0) cerr << ", ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __VA_ARGS__)
void localTest() {
    #ifndef ONLINE_JUDGE
        freopen("inp", "r", stdin);
        freopen("out", "w", stdout);
    #endif      
}
#define ld double
const ll N = 3e2 + 5;
ld dp[N][N][N];
ll n, memo[N][N][N];
ld doit(ll c1, ll c2, ll c3) {
	if(!c1 && !c2 && !c3) return 0.0;
	ld &ret = dp[c1][c2][c3];
	if(memo[c1][c2][c3]) return ret;
	memo[c1][c2][c3] = 1;
	ld p1 = (ld)c1 / n, p2 = (ld)c2 / n;
	ld p3 = (ld)c3 / n, p0 = (ld)(n - c1 - c2 - c3) / n;
	ld ans = 1;
	if(c1) ans += p1 * doit(c1 - 1, c2, c3);
	if(c2) ans += p2 * doit(c1 + 1, c2 - 1, c3);
	if(c3) ans += p3 * doit(c1, c2 + 1, c3 - 1); 
	ans /= (1 - p0);
	return ret = ans;
}
int main() {

    localTest();
    fastio;
 	map<ll, ll> has;
 	cin >> n;
 	vector<ll> A(n);
 	for(auto &x : A) cin >> x, has[x]++;
 	cout << setprecision(10) << doit(has[1], has[2], has[3]) << "\n";
    return 0;
}