#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,ans = 0;
	vector<int> a(200010,0),b(200010,0);
	cin >> n;
	for (int i = 0;i < n;++i) cin >> a[i];
	for (int i = 0;i < n;++i) cin >> b[i];

	for (int i = 29;i > 0;--i) {
		int cnt = 0;
		int T = (1 << i-1);
		for (int j = 0;j < n;++j) b[j] %= 2*T;
		sort(b.begin(),b.begin()+n);
		for (int j = 0;j < n;++j) {
			a[j] %= 2*T;
			cnt += lower_bound(b.begin(),b.begin()+n,2*T-a[j])-lower_bound(b.begin(),b.begin()+n,T-a[j]);
			cnt += lower_bound(b.begin(),b.begin()+n,4*T-a[j])-lower_bound(b.begin(),b.begin()+n,T*3-a[j]);
			cnt %= 2;
		}
		if (cnt) ans += T;
	}

	cout << ans << endl;
	return 0;
}