#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;
const int maxN = 2e5 + 55;

int n;
ll a[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	if(a[1] > 0){
		cout << "-1\n";
		return 0;
	}
	
	ll ans = 0;
	for(int i = 1; i + 1 <= n; i++){
		if(a[i] + 1 < a[i + 1]){
			cout << "-1\n";		
			return 0;
		}

		if(a[i] + 1 == a[i + 1]){
			ans++;
		} else {
			ans += a[i + 1];
		}
	}

	cout << ans << '\n';

	return 0;
}