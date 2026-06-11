#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	vector<int> cnt(3);
	rep(i, n) {
		if (p[i] <= a) cnt[0]++;
		else if (p[i] <= b) cnt[1]++;
		else cnt[2]++;
	}
	cout << min(cnt[0], min(cnt[1], cnt[2])) << endl;
	return 0;
}