#define LOCAL
#include "bits/stdc++.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define LLINF ((long long) 1e16)//1234567890987654321
#define INF 1234567890ll
#define pb push_back
#define eb emplace_back
#define ins insert
#define f first
#define s second	
#define db 0
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos((ld)-1.0))
#define MAXN (3006)
#define ll long long int 
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
#define FOR(ii, ss, ee) for(ll ii = ss; ii < (ll)ee; ++ii)
#define space " "
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define ph push
#define btinpct(x) __builtin_popcountll((x))
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
typedef pair <pi, pi> dpi;
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss
string to_string(char c) {string s(1,c);return s;}string to_string(bool b){return (b ? "true" : "false");}template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}void degug_out() { cerr << endl; }template <typename Head, typename... Tail>void degug_out(Head H, Tail... T) {cerr << " " << to_string(H);degug_out(T...);}inline ll gcd(ll a,ll b){if(a>b)swap(a,b);if(a==0)return b;return gcd(b%a,a);}
#ifdef LOCAL
#define degug(...) cerr << "[" << #__VA_ARGS__ << "]:", degug_out(__VA_ARGS__)
#else
#define degug(...) 42
#define cerr if(0)cout
#endif
ll n,a,b;
void solve() {
	// split into A non empty buckets each with <= b elements
	if(a*b<n){
		cout<<"-1\n";return;
	}
	ll ls=0;ll left=n-a; // reserve 1 for each bkt
	for(ll i=0;i<a;++i){
		ll tocout=1+min(b-1,left);
		for(ll i=ls+tocout;i>ls;--i){
			cout<<i<<' ';
		}
		ls+=tocout;
		left-=(tocout-1);
	}
	return;
}
int main()
{
	FAST
	// freopen("out1","w",stdout);
	cin>>n>>a>>b;
	if(a+b<n){
		if(a==1||b==1){
			cout<<"-1\n";
			return 0;
		}
		solve();
		return 0;
	}
	if(a+b>n+1||a+b<n){
		cout<<"-1\n";return 0;
	}
	if(a+b==n+1){
		ll start=n-a+1;
		FOR(i,start,n+1)cout<<i<<' ';
		start--;
		while(start){
			cout<<start<<' ';start--;
		}
	}else{
		if(a==1||b==1){
			cout<<"-1\n";
			return 0;
		}
		ll start=n-a+1;
		FOR(i,start,n+1)cout<<i<<' ';
		start--;
		while(start>2){
			cout<<start<<' ';start--;
		}
		cout<<1<<' '<<2<<'\n';
	}
}
/*
 * 
143766 3908 5617
*/ 
