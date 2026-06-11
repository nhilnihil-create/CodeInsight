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

string s;
bool was[maxn];
void solve(){
	cin >> s;
	if(sz(s) == 26){
		string nxt = s;
		if(!next_permutation(all(nxt))){
			cout << -1;
			return;
		}
		//next_permutation(all(nxt));
		forn(i, 0, sz(nxt) - 1){
			if(nxt[i] > s[i]){
				forn(j, 0, i) cout << nxt[j];
				return;
			}
		}
		cout << -1;
	}else{
		for(auto x : s) was[x - 'a'] = 1;
		cout << s;
		forn(i, 0, 25) 
			if(!was[i]){
				putchar(i + 'a');
				return;
			}
	}
}

int main () {
  solve();
}



