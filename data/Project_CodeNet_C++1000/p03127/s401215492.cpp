#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n;
	cin >> n;
	ll arr[n];
	cin >> arr[0];
	ll ans = arr[0];
	for (int i = 1 ; i< n;  i++){
		cin >> arr[i];
		ans = __gcd(arr[i] , ans);
	}
	cout << ans << endl;
}
