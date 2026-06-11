#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;
const int maxN = 2e5 + 55;

int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	multiset<ll> se;
	for(int i = 1; i <= n; i++){
		ll x;	cin >> x;	
		se.insert(x);
	}
	
	int ans = 0;
	while(!se.empty()){
		ll mx = *se.rbegin();
		ll target = 1;
		while(target <= mx){
			target *= 2;
		}
		se.erase(se.find(mx));
		target -= mx;
		if(se.count(target)){
			ans++;
			se.erase(se.find(target));
		}
	}
	
	cout << ans << '\n';

	return 0;
}