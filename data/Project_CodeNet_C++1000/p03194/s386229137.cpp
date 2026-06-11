#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);  
	long long n, p;
	cin >> n >> p;
	long long ans = 1;
	map<long long, long long> mp;
	for(long long i = 2; i * i <= p; i++) {
		while(p % i == 0) {
			mp[i]++;
			p /= i;
		}
	}
	if(p != 1) {
		mp[p]++;
	}
	for(auto i : mp) {
		if(i.second >= n) {
			ans *= pow(i.first, i.second / n);
		}
	}
	cout << ans << endl;
	
	return 0;	
}
