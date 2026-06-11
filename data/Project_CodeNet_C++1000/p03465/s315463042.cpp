#include <bits/stdc++.h>
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)5e3 + 100;
const int mod = (int)1e9 + 7;
const int P = (int) 1e6 + 7; 
const double pi = acos(-1.0);
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;                        


int n, sum, x;
bitset<2000 * 2000 + 100> dp;
void solve(){
	scanf("%d", &n);
	dp[0] = 1;
	forn(i, 1, n){
		scanf("%d", &x);
		dp |= (dp << x);
		sum += x;
	}
	forn(i, (sum + 1) / 2, sum)
		if(dp[i]){
			printf("%d", i);
			return;
		}
}
int main () {
	int t = 1;
	while(t--)
		solve(); 
}