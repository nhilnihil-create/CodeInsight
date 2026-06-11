#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n), bit(40);
	for(int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; ++i){
		for(int j = 0; j < 40; j++){
			if(a[i] & (1LL << j)) bit[j]++;
		}
	}
	long long now = 0;
	for(int i = 39; i >= 0; i--){
		long long next = now + (1LL << i);
		if(next <= k && bit[i] * 2 < n) now = next;
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) ans += now ^ a[i];
	cout << ans << endl;
	return 0;
}
