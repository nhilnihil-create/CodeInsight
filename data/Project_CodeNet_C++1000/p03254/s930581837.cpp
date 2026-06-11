#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);

	sort(a.begin(), a.end());

	int ans = 0;
	rep(i, n-1){
		if(a.at(i) <= x){
			x -= a.at(i);
			ans++;
		}
	}
	if(x == a.at(n-1))
		ans++;
	cout << ans << endl;
}