//{
#include<bits/stdc++.h>
using namespace std;
 
#define DEBUG

typedef long long int ll;
typedef long double ld;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define MOD (ll)(1e9 + 7)
#define vi vector<int>
#define vii vector<vector<int> >
#define vl vector<ll>
#define vll vector<vector<ll> >
#define vc(T, nm) vector<T> nm
#define pb push_back
#define popb pop_back
#define si set<int>
#define sl set<ll>
#define F first
#define S second
#define pii pair<int, int>
#define mp make_pair
#define ins insert
#define ers erase
#define endl "\n"
#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD
#define adr(a, b) ((a % MOD) + (b % MOD)) % MOD
#define FORA(x, s, e, inc) for(ll x = s; x != e; x += inc)
#define ROFA(x, s, e, inc) for(ll x = s; x != e; x -= inc)
#define FOR(x, s, e) FORA(x, s, e, 1)
#define ROF(x, s, e) ROFA(x, s, e, 1)
#define loop(x, n) FOR(x, 0, n)
#define rd1(t, a) 					t a; cin >> a;
#define rd2(t, a, b) 				rd1(t, a); rd1(t, b); 
#define rd3(t, a, b, c) 			rd2(t, a, b); rd1(t, c);
#define rd4(t, a, b, c, d) 			rd3(t, a, b, c); rd1(t, d);
#define rd5(t, a, b, c, d, e) 		rd4(t, a, b, c, d); rd1(t, e);
#define rd6(t, a, b, c, d, e, f) 	rd5(t, a, b, c, d, e); rd1(t, f);
#define rdA(t, nm, len)				t nm[len]; loop(i, len) {cin >> nm[i];}
#ifdef DEBUG
	#define deb(v) cout << endl << #v << ": " << v << endl
	#define db1(v) cout << endl << #v << ": " << "[ "; for(auto x: v) {cout << x << " ";}; cout << "]" << endl;
	#define db2(v) cout << endl << #v << ": " << endl; for(auto r: v) {cout << "[ "; for(auto x: r) {cout << x << " ";}; cout << "]" << endl;};
	#define dbl cout << "-------------------------------" << endl
#else
	#define deb(v)
	#define db1(v)
	#define db2(v)
	#define dbl
#endif
//}

vl parent(100005), weight(100005);

ll findset(ll u) {
    if(parent[u] == u)
        return u;
    return parent[u] = findset(parent[u]);
}

void joinset(ll u, ll v) {
    ll a = findset(u);
    ll b = findset(v);
    if(a != b) {
        parent[a] = b;
        weight[b] += weight[a];
    }
}

ll solve(ll n, ll m, vl &A, vector<pair<ll, ll> > &P) {
    FOR(i, 0, 100005) {
        parent[i] = i;
        weight[i] = 1;
    }
    
    FOR(i, 0, m) {
        ll u = P[i].F, v = P[i].S;
        joinset(u, v);
    }
    
    ll ct = 0;
    FOR(i, 0, n) {
        if(A[i] == i + 1)
            ct++;
        else {
            if(findset(i + 1) == findset(A[i]))
                ct++;
        }
    }
    
    return ct;
}

void Input() {
    rd2(ll, n, m);
    vl A(n);
    FOR(i, 0, n)
        cin >> A[i];
    vector<pair<ll, ll> > P(m);
    FOR(i, 0, m)
        cin >> P[i].F >> P[i].S;
    cout << solve(n, m, A, P);
}

int main() {
	
	fastio;

    // rd1(ll, t);
	ll t = 1;

    while(t--) {
        Input();
    }
    
	return 0;
}