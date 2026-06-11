#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,ans = 0;
	vector<int> a(200010,0),b(200010,0),c(200010,0);
	cin >> n;
	for (int i = 0;i < n;++i) cin >> a[i];
	for (int i = 0;i < n;++i) cin >> b[i];

	for (int i = 1;i < 30;++i) {
		int cnt = 0;
		for (int j = 0;j < n;++j) c[j] = b[j]%(1 << i);
		sort(c.begin(),c.begin()+n);
		for (int j = 0;j < n;++j) {
			cnt += lower_bound(c.begin(),c.begin()+n,(1 << i)-a[j]%(1 << i))-lower_bound(c.begin(),c.begin()+n,(1 << i-1)-a[j]%(1 << i));
			cnt += lower_bound(c.begin(),c.begin()+n,(1 << i+1)-a[j]%(1 << i))-lower_bound(c.begin(),c.begin()+n,(1 << i-1)*3-a[j]%(1 << i));
			cnt %= 2;
		}
		if (cnt) ans += (1 << i-1);
	}

	cout << ans << endl;
	return 0;
}