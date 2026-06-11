#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int main() {
	vector<int> n(4);
	rep(i, 4) cin >> n[i];
	vector<int> cnt(4);
	rep(i, 4) {
		if (n[i] == 1) cnt[0]++;
		else if (n[i] == 4) cnt[1]++;
		else if (n[i] == 7) cnt[2]++;
		else if (n[i] == 9) cnt[3]++;
	}
	bool ans = true;
	rep(i, 4) {
		if (cnt[i] != 1) ans = false;
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}