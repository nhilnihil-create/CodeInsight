#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	vector<int> a(6);
	rep(i, 6) cin >> a[i];
	vector<int> ans(4);
	rep(i, 6) ans[a[i]-1]++;
	bool b = true;
	rep(i, 4) {
		if (ans[i] == 3) b = false;
	}
	if (b) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}