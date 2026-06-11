#include<bits/stdc++.h>
 
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
 
const int maxn = (int)1e5 + 100;
const int mod = (int)1e9 + 7;
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;

int n, was[maxn];
vi ans;
void solve(){
	cin >> n;
	if(n == 3){
		puts("2 5 63");
		return;
	}
	int s = 0;
	forn(i, 1, maxn){
		if(i % 2 == 0 || i % 3 == 0){
			ans.pb(i);
			was[i] = 1;
			s = (s + i) % 6;
			if(sz(ans) == n) break;
		}
	}
	int add = (6 - s) % 6;
	if(add){
		for(auto &x : ans){
			if(was[x + add]) continue;
			if((x + add) % 2 == 0 || (x + add) % 3 == 0){
				x += add;
				break;
			}
		}
	}
	for(auto x : ans) cout << x << " ";
}

int main () {
  solve();
}



