#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define FORR(I,A,B) for(ll I = ((B)-1); I >= (A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
#define pri(a) cout << (a) << endl


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b;
	cin >> a >> b;
	char ans[100][100];
	FOR(i,0,100){
		FOR(j,0,100){
			if(i<50)ans[i][j] = '.';
			else ans[i][j] = '#';
		}
	}
	// a w .
	// b b #
	a--;
	b--;
	ll i = 0;
	ll j = 0;
	while(b--){
		ans[i][j] = '#';
		j += 2;
		if(j>=49){
			j = 0;
			i += 2;
		}
	}
	i = 51;
	j = 0;
	while(a--){
		ans[i][j] = '.';
		j += 2;
		if(j>=49){
			j = 0;
			i += 2;
		}
	}
	cout << 100 << " " << 100 << endl;
	FOR(i,0,100){
		FOR(j,0,100){
			cout << ans[i][j];
		}
		cout << endl;
	}

}