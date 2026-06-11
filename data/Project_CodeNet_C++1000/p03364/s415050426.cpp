#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, a[1000][1000];
string s[1000];

void check(ll si, ll sj){
	//print('s')
	rep(i, 0, n){
		rep(j, 0, n){
			//print(s[si+i][sj+j])
			//print(s[sj+j][si+i])
			if(s[si+i][sj+j] != s[si+j][sj+i]){
				rep(k, 0, (min(i, j)+1)){
					a[si+k][sj+k] = -1;
				}
				return;
			}
		}
	}
	a[si][sj] = 1;
}

void mcheck(ll si, ll sj){
	rep(i, 0, n){
		ll j = n;
		if(s[si+i][sj+j] != s[si+j][sj+i]){
			rep(k, 0, (min(i, j)+1)){
				a[si+k][sj+k] = -1;	
			}
			return;
		}
	}
	a[si][sj] = 1;
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, 0, n){
		cin >> s[i];
		s[i] += s[i];
		s[i+n] = s[i];
	}
	//rep(i, 0, 2*n){print(s[i])}
	memset(a, 0, sizeof(a));
	
	rep(i, 0, n){
		rep(j, 0, n){
			if(i == 0 || j == 0 || (a[i][j] == 0 && a[i-1][j-1] != 1)){
				check(i, j);
			}
			else{
				if(a[i][j] == 0 && a[i-1][j-1] == 1){
					mcheck(i, j);
				}
			}
		}
	}
	
	ll ans = 0;
	rep(i, 0, n){rep(j, 0, n){
		//print(a[i][j]);
		if(a[i][j] == 1){ans++;}
	}}
	print(ans)
	return 0;
}