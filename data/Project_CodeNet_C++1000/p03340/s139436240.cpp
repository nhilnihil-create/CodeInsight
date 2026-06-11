#define rep(i, n) for(int i=0; i<n; i++)
template<class T> inline void chmin(T & a, const T b) { if (a > b) a = b; }
template<class T> inline void chmax(T & a, const T b) { if (a < b) a = b; }
typedef long long llong;

#include <bits/stdc++.h>
using namespace std;
int main(void) {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) scanf("%d", &a[i]);

	llong res = 0;
	llong sum = 0;
	int right = 0;
	for (int left = 0; left < n; left++) {
		while (right < n && (sum ^ a[right]) == (sum + a[right])) {
			sum += a[right];
			right++;
		}

		res += (right - left);

		if (left == right) right++;
		else sum -= a[left];
	}
	cout << res << endl;

	return 0;
}