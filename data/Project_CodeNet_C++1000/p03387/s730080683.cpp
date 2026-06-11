#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	vector<int> d(3);
	rep(i,3) cin >> d[i];
	sort(d.begin(),d.end());
	int ans = 0;
	if(d[0] % 2 != d[1] %2){
		ans++;
		d[0]++;
		d[2]++;
	}
	ans += d[2] - d[1] + (d[1] -d[0])/2;
	cout << ans << endl;
	return 0;
 }