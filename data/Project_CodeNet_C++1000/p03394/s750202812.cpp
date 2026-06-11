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

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	vector<ll> t, h, f, s, ans;
	rep(i, 1, 5000){
		t.push_back(6*i-4);
		h.push_back(6*i-3);
		f.push_back(6*i-2);
		s.push_back(6*i);
	}
	
	ll n;
	cin >> n;
	if(n == 3){cout << "2 5 63" << endl; return 0;}
	if(n == 4){cout << "2 5 20 63" << endl; return 0;}
	
	ll ti = min(5000LL, n/2-1);
	ll fi = min(5000LL, n/2-1);
	ll hi = min(5000LL, 2*((n-ti-fi)/2));
	ll si = n-ti-hi-fi;
	
	zep(i, 0, ti){ans.push_back(t[i]);}
	zep(i, 0, hi){ans.push_back(h[i]);}
	zep(i, 0, fi){ans.push_back(f[i]);}
	zep(i, 0, si){ans.push_back(s[i]);}
	
	zep(i, 0, ans.size()){cout << ans[i] << " ";}cout << endl;
	return 0;
}