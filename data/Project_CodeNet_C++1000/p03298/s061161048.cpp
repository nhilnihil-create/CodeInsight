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
#define PI (acos(-1))
#define MAXN (300006)
#define ll long long int 
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
#define FOR(ii, ss, ee) for(ll ii = ss; ii < ee; ++ii)
#define space " "
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define ph push
#define emp emplace
#define btinpct(x) __builtin_popcountll(x)
#define p2(x) (1LL<<(x))
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
typedef pair <pi, pi> dpi;
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss
ll n; ll half;
char A[40];
map<string,ll>mp;
bool palin(string x) {
	string xx=x;
	reverse(all(xx));
	return x==xx;
}
void backdp(ll pos, ll bm) {
	if(pos==n){
		string red="";
		string blue="";
		string put="";
		FOR(i,half,n){
			if(bm&(1ll<<i))red+=A[i];
			else blue+=A[i];
		}
		reverse(all(red));
		reverse(all(blue));
		mp[red+' '+blue]++;
		return;
	}
	backdp(pos+1,bm);
	backdp(pos+1,bm|(1ll<<pos));
	return;
}
ll ans;
int main()
{
	FAST
	cin>>n;n*=2;
	FOR(i,0,n)cin>>A[i];
	half=n/2;
	// first half until < half, second half until rest
	backdp(half,0);
	FOR(bm,0,(1ll<<half)){
		string red="";
		string blue="";
		string put="";
		FOR(i,0,half){
			if(bm&(1ll<<i))red+=A[i];
			else blue+=A[i];
		}
		ans+=mp[red+' '+blue];
	}
	cout<<ans;
}
