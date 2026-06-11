#include<bits//stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
int n, m, x, y,z;
int main(void) {
	cin >> n >> m; vector<int> a(100010, 0);
	rep(i, n) {cin >> x >> y >> z;a[x - 1]++; a[y]--;} x = 0;
	rep(i, 100009) a[i + 1] += a[i];
	rep(i, 100010) x = max(x, a[i]);
	cout << min(x,m) << endl;
}