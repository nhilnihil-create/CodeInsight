#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector< pair<pll, ll> > E;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n = 20;
	ll L;
	cin >> L;
	for(int i = 1; i < 20; i++){
		E.pb({{i, i + 1}, 0});
		if(L == 1) continue;
		if(L & 1){
			L--;
			E.pb({{i, n}, L});
		}
		if(L){
			E.pb({{i, i + 1}, L / 2});
			L /= 2;
		}
	}


	cout << "20 " << E.size() << '\n';
	for(auto x : E) cout << x.F.F << ' ' << x.F.S << ' ' << x.S << '\n'; 
	return 0;
}
