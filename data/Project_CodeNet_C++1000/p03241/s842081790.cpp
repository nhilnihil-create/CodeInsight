#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N, M;
	cin >> N >> M;

	priority_queue<ll> div;
	for (ll ii = 1; ii*ii <= M; ++ii){
		if (M % ii == 0){
			div.push(ii);
			if (M / ii != ii){
				div.push(M / ii);	//重複しないなら相方も追加
			}
		}
	}

	ll ans = 1;
	while(!div.empty()) {
		ll val = div.top();
		div.pop();
		if (M / val >= N){
			ans = val;
			break;
		}		
	}

	cout << ans << endl;

	return 0;
}
