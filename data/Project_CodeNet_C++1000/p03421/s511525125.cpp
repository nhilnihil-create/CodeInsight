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

ll n, a, b;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> a >> b;
	if(a+b-1 <= n && n <= a*b){
		rrep(j, b, 1){
			cout << j << " ";
		}
		ll cnt = b;
		ll acnt = 1;
		rep(i, 2, a){
			if(n-cnt > a-acnt){
				ll can = min(n-acnt*b-(a-acnt)+1, b);
				rrep(j, cnt+can, cnt+1){
					cout << j << " ";
				}
				cnt += can;
				acnt++;
			}
			else{
				cout << cnt+1 << " ";
				cnt++;
				acnt++;
			}
		}
		cout << endl;
	}
	else{
		print(-1)
	}
	return 0;
}