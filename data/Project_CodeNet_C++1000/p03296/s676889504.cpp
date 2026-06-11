#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i, N) cin >> a.at(i);
	int ans = 0;
	int count = 1;
	rep(i, N - 1) {
		if (a.at(i) == a.at(i + 1)) count++;
		else {
			ans += count / 2;
			count = 1;
		}
	}
	ans += count / 2;
	cout << ans << endl;
	return 0;
}