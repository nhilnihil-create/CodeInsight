#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> nums(40);

	for(int i=0; i<n; i++){
		cin >> a[i];
		for(int j=0; j<40; j++) if(a[i] & (1ll << j)) nums[j]++;	
	}

	ll x = 0;
	for(int i=39; i>=0; i--){
		if(nums[i]*2 <= n) x += (1ll << i);
		if(x > k) x -= (1ll << i);
	}

	ll sum = 0;
	for(ll A : a) sum += A^x;
	cout << sum << endl;

	return 0;
}
