#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;
	ll a[n];
	ll res = 0;
	for(ll i=0; i<n; i++){
		cin >> a[i];
		res += a[i]-1;
	}
	cout << res;
	return 0;
}