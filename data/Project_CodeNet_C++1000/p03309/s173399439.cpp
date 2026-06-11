#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define ar array

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int > pii;
const ll MOD =1e9+7;


void solve(){
	int n; cin >> n;
	vi a(n); 
	for(int i = 0; i < n; ++i)
		cin >> a[i], a[i] -= (i+1);
	sort(all(a));
	
	ll ans=0,s = a[n/2];
	for(int i = 0; i < n; ++i)
		ans += abs(a[i]-s);
	cout << ans;
	
}

int main(){
	int t=1;
	//cin >> t;
	while(t--){
		solve();
		cout <<'\n';
	}
}
