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

ll n;
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> s;
	n = s.size();
	if(s[n-1] == '1'){
		print(-1)
		return 0;
	}
	else{
		rep(i, 0, n/2){
			if(s[i] != s[n-2-i]){
				print(-1)
				return 0;
			}
		}
		if(s[0] == '0'){
			print(-1)
			return 0;
		}
		
		vector<P> ans;
		ans.push_back(P(1, 2));
		ll at = 2;
		ll cnt = 2;
		rep(i, 1, n/2){
			if(s[i] == '0'){
				ans.push_back(P(at, cnt+1));
				cnt++;
			}
			else{
				ans.push_back(P(at, cnt+1));
				cnt++;
				at = cnt;
			}
		}
		rep(i, cnt+1, n){
			ans.push_back(P(at, i));
		}
		for(ll i = 0; i < ans.size(); i++){
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
	return 0;
}