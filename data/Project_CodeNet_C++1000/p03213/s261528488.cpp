#include "bits/stdc++.h"
using namespace std;

//素数判定
bool prime(int n) {
	if (1 == n) {
		return false;
	}
	for (int i = 2; i*i <= n; i++) {
		if (0 == n % i) {
			return false;
		}
	}
	return true;
}

int count(int  n,int m) {
	int ret = 0;
	for (int l = 1;l<=m;++l) {
		int tmp = l;
		while (0 == tmp%n) {
			++ret;
			tmp /= n;
		}
	}
	return ret;
}

int main() {
	int N;
	cin >> N;
	vector<int>vec;
	for (int n = 1;n<=N;++n) {
		if (prime(n)) {
			vec.push_back(count(n,N));
		}
	}
	sort(vec.begin(),vec.end());
	int ans = 0;
	ans += vec.end()-lower_bound(vec.begin(), vec.end(), 74); 
	ans += (vec.end() - lower_bound(vec.begin(), vec.end(), 24))*(vec.end() - lower_bound(vec.begin(), vec.end(), 2)-1); 
	ans += (vec.end() - lower_bound(vec.begin(), vec.end(), 14))*(vec.end() - lower_bound(vec.begin(), vec.end(), 4) - 1); 
	ans += (vec.end() - lower_bound(vec.begin(), vec.end(), 4))*(vec.end() - lower_bound(vec.begin(), vec.end(), 4) - 1)*(vec.end() - lower_bound(vec.begin(), vec.end(), 2) - 2)/2;
	cout << ans <<endl;
	return 0;
}
