#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int main(void){
	vector<int> a(3);
	rep(i, 3) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	if(a[0] % 2 != a[1] % 2){
		ans++;
		a[0]++;
		a[2]++;
	}
	ans += a[2]-a[1] + (a[1]-a[0])/2;
	cout << ans << endl;
	return 0;
}
