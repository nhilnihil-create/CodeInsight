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
	int n, k; cin >> n >> k;
	int cnt[k];
	memset(cnt,0,sizeof cnt);
	for(int i = 1; i <= n; ++i)
		cnt[i%k]++;
	ll ans= 1LL*cnt[0]*cnt[0]*cnt[0];
	if(k%2==0)
		ans += 1LL*cnt[k/2]*cnt[k/2]*cnt[k/2];
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
