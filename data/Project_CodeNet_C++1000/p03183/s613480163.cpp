#include <bits/stdc++.h>     
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define int ll
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)1e3 + 10;
const int mod = (int)1e9 + 7;
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;

int n;
pair<pii, int> a[maxn];                  
bool cmp(pair<pii, int> a, pair<pii, int> b){
	return (a.f.f + a.f.s) < (b.f.f + b.f.s);
}              
int dp[maxn][maxn * 10];
int calc(int pos, int s){
	if(s > 10000) return 0;
	if(pos == n + 1)
		return 0;
	int &res = dp[pos][s];
	if(res != -1)
		return res;
	res = calc(pos + 1, s);
	if(s <= a[pos].f.s)
		res = max(res, calc(pos + 1, s + a[pos].f.f) + a[pos].s);
	return res;	
}
main () {
	cin >> n;
	forn(i, 1, n)
		cin >> a[i].f.f >> a[i].f.s >> a[i].s;
	sort(a + 1, a + n + 1, cmp);
	memset(dp, -1, sizeof(dp));
	cout << calc(1, 0);	
}
