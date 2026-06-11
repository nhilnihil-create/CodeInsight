#include <bits/stdc++.h>
 
using namespace std;
 
using tint = long long;
using ld = long double;
 
#define forsn(i, s, n) for(int i = s; i < int(n); i++)
#define forn(i, n) forsn(i, 0, n)
 
using vi = vector<tint>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define DBG(x) cerr << #x << " = " << x << endl;
 
const int MOD = 1e9+7;
const int MX = 5e5+5;
const tint INF = 1e18;
const ld PI = acos(ld(-1)); 
 
void NACHO(string name = "out"){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen((name+".in").c_str(), "r", stdin);
    //freopen((name+".out").c_str(), "w", stdout);
}
 
int main(){
	NACHO();
	int n;
	cin >> n;
	vi a (n);
	forn(i, n) cin >> a[i];
	function<tint(tint)> f = [&](tint b){
		tint tot = 0;
		forn(i, n) tot+=abs(a[i]-(b+i+1));
		return tot;
	};
	tint lo = -INF, hi = INF;
	while (hi - lo > 1){
		tint mid = (hi + lo)>>1;
		if (f(mid) < f(mid + 1)) 
			hi = mid;
		else 
			lo = mid; 
	}
	tint mini = INF;
	forsn(i, lo, hi+1) mini = min(mini, f(i));
	cout << mini << "\n";
}
