#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n;
	ll h, w;
	cin >> n >> h >> w;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	int cnt = 0;
	rep(i, n) {
		if (a[i] >= h&&b[i] >= w) cnt++;
	}
	cout << cnt << endl;
	return 0;
}