#define LOCAL
#include "bits/stdc++.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
#define pb push_back
#define eb emplace_back
#define ins insert
#define f first
#define s second	
#define db 0
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos((ld)-1.0))
#define MAXN (300006)
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
ll n,A[MAXN],B[MAXN];
int main()
{
	FAST
	cin>>n;
	FOR(i,0,n)cin>>A[i]>>B[i];
	bool eq=1; ll ans=LLINF; ll sum=0;
	FOR(i,0,n){
		eq&=(A[i]==B[i]);
		sum+=A[i];
		if(A[i]>B[i])ans=min(ans,B[i]);
	}
	if(eq)cout<<0<<'\n';
	else cout<<sum-ans<<'\n';
}
