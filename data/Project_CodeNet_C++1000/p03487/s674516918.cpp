#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int a[N+1];
	rep(i,N) cin >> a[i];
	a[N] = -1;
	sort(a,a+N);
	int now = 0;
	int cnt = 0;
	int ans = 0;
	rep(i,N+1) {
		if (now == a[i] ) cnt++;
		else {
			if (cnt >= now) ans += cnt - now;
			else ans += cnt;
			now = a[i];
			cnt = 1;
		}
	}
	cout << ans << endl;

	return 0;
}
