#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>
using namespace std;
int p = 1000000007;
#define vel vector<int>
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
	int n; cin >> n;
	vel a(n);
	int sum = 0;
	rep(i, n) { cin >> a[i]; sum += a[i]; }
	const int bit_sz = 2000001;
	bitset<bit_sz> bs;
	bs[0] = 1;
	rep(i, n) {
		bs |=bs << a[i];
	}
	int ans = 0;
	for(int i=0;i*2<=sum;i++) {
		if (bs[i]) { ans = i; }
	}
	cout << sum-ans << endl;
	return 0;
}
