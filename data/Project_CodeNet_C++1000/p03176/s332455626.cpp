#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define F first
#define S second
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define pdd pair<ld, ld>
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define uid uniform_int_distribution
#define FILE ifstream in("input.txt");ofstream out("output.txt");
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;
typedef string str;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int G = 2e5+5;
ll a;
vec<ll> h, c;
ll BIT[G];

ll pref_mx(int p){
    ll o = 0;
    for(; p>0; p -= p&-p) o = max(o, BIT[p]);
    return o;
}

void upd(int p, ll val){
    for(; p<G; p += p&-p) BIT[p] = max(BIT[p], val);
}

int main() {
    fast;
    memset(BIT, 0, sizeof(BIT));
    cin>>a;
    h = vec<ll>(a);
    c = vec<ll>(a);
    for(int q=0; q<a; q++) cin>>h[q];
    for(int q=0; q<a; q++) cin>>c[q];
    vec<ll> dp(a);
    for(int q=0; q<a; q++){
        dp[q] = c[q] + pref_mx(h[q]);
        upd(h[q], dp[q]);
    }
    ll o = 0;
    for(ll i : dp) o = max(o, i);
    cout<<o;
}