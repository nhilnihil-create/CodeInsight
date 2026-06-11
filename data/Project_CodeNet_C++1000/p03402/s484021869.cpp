#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll a, b, ans[108][108];

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> a >> b;

	memset(ans, 0, sizeof(ans));
	rep(i, 1, 100){
		rep(j, 1, 50){
			ans[i][j] = 1;
		}
	}
	
	rep(k, 2, a){
		ans[2*(k%50)+1][2*(k/50)+2] = 0;
	}
	rep(k, 2, b){
		ans[2*(k%50)+1][2*(k/50)+52] = 1;
	}
	
	print("100 100")
	rep(i, 1, 100){
		rep(j, 1, 100){
			char c = (ans[i][j] == 0)? '.' : '#';
			cout << c;
		}
		cout << endl;
	}
	
	return 0;
}