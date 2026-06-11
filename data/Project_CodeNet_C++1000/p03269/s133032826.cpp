#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int long long
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define sz(x) (int)x.size()
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;

#ifndef LOCAL
#pragma GCC optimize ("O2")
#define endl '\n'
#endif

template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

ll pwr(ll a,ll b, ll mod){
    a %= mod;
    int ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

vector<vector<int>> z;
void add(int u,int v, int val){
	z.pb({u, v, val});
}
void solve(){
	int l;
	cin >> l;
	int c = (1 << 17);
	fr(i, 2, 19){
		add(i, i + 1, c);
		add(i, i + 1, 0);
		c >>= 1;
	}
	int cur = 0;
	if(l & (1 << 19)){
		add(1, 2, 0);
		add(1, 2, (1 << 18));
		if(l & (1 << 18)){
			add(1, 2, (1 << 19));
			cur = (1 << 19) ^ (1 << 18);
		}
		else{
			cur = (1 << 19);
		}
	}
	else if(l & (1 << 18)){
		cur = (1 << 18);
		add(1, 2, 0);
	}
	for(int i = 17; i >= 0; i--){
		if((l >> i) & 1){
			int node = 20 - i;
			add(1, node, cur);
			cur += (1 << i);
		}
	}
	cout << 20 << " " << sz(z) << endl;
	for(auto e : z){
		cout << e[0] << " " << e[1] << " " << e[2] << endl;
	}
}
signed main(){
    IO;
    #ifdef LOCAL
        freopen("inp.txt","r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    fr(tt, 1, t){
        solve();
    }
    return 0;
}