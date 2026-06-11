#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;
const int maxN = 2e5 + 55;

int n;
ll a[maxN];

bool chk(ll x){
	map<ll, ll> mp;
	for(int i = 2; i <= n; i++){
		if(a[i - 1] >= a[i]){
			if(x == 1){
				return false;
			}
			while(!mp.empty()){
				ll mx = mp.rbegin()->first;
				if(mx > a[i]){
					mp.erase(mx);
				} else {
					break;
				}
			}

			int j = a[i];
			while(j > 0 && mp[j] + 1 == x){
				mp.erase(j);
				j--;
			}
			if(j == 0){
				return false;
			}
			mp[j]++;
		}
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int lo = 1, hi = n, ans = n;
	while(lo <= hi){
		int mid = (lo + hi) / 2;
		if(chk(mid)){
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}