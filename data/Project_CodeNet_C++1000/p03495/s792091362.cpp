#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> cnt(n);
	rep(i, n){
		int d;
		cin >> d;
		cnt.at(d-1)++;
	}
	
	sort(cnt.begin(), cnt.end());
	
	int ans = 0;
	rep(i, n-k) ans += cnt.at(i);

	cout << ans << endl;
}