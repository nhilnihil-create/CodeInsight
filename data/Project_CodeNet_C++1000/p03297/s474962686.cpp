#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll t, a, b, c, d;

ll gcd(ll _n1, ll _n2){
	if(_n1 < _n2){ll tmp = _n1; _n1 = _n2; _n2 = tmp;}
	if(_n1 == _n2 || _n2 == 0){return _n1;}
	return gcd(_n2, _n1%_n2);
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> t;
	rep(i, 1, t){
		cin >> a >> b >> c >> d;
		if(b > a || d < b){
			print("No")
		}
		else{
			if(c >= b){
				print("Yes")//no
			}
			else{
				ll syuki = gcd(b, d);
				ll table = a%b;
				ll grgr = (c-table)/syuki;
				//cout << syuki << table << grgr << endl;
				if(table > c || table+(grgr+1)*syuki < b){
					print("No")
				}
				else{
					print("Yes")
				}
			}
		}
	}
	return 0;
}