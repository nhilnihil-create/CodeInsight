#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	vector<int> a(5);
	int k;
	rep(i,5){
		cin >> a[i];
	}
	cin >> k;
	string ans = "Yay!";
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 5; j++){
			if (a[j] - a[i] > k) ans = ":(";
		}
	}
	cout << ans << endl;
	return 0;
}
