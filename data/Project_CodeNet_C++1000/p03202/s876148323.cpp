#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, a[200008];

bool f(ll x){
	map<ll, ll> dp;
	zep(i, 1, n){
		if(a[i] <= a[i-1]){
			if(x == 1){
				return false;
			}
			if(a[i] < a[i-1]){
				vector<ll> er;
				for(auto it = dp.upper_bound(a[i]); it != dp.end(); it++){
					er.push_back((*it).first);
				}
				zep(j, 0, er.size()){
					dp.erase(er[j]);
				}
			}
			
			ll at = a[i];
			if(dp.find(at) != dp.end()){(*dp.find(at)).second++;}
			else{dp[at] = 1;}
			
			while(dp.find(at) != dp.end() && dp[at] == x){
				dp.erase(at);
				at--;
				if(dp.find(at) == dp.end()){
					dp[at] = 1;
				}
				else{
					dp[at]++;
				}
				if(at < 1){return false;}
			}
		}
	}
	return true;
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	zep(i, 0, n){cin >> a[i];}
	
	ll ok = n;
	ll ng = 0;
	while(ok-ng > 1){
		ll mid = (ok+ng)/2;
		if(f(mid)){ok = mid;}
		else{ng = mid;}
	}
	print(ok)
	return 0;
}
