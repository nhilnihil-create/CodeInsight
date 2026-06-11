#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

vector<int> a(5);

int main(void){
	rep(i, 5) cin >> a[i];
	sort(a.begin(), a.end());
	int ans = INT_MAX;
	do{
		int t = 0;
		rep(i, 4) t+=((a[i]-1)/10+1)*10;
		ans = min(ans, t+a[4]);
	}while(next_permutation(a.begin(), a.end()));
	cout << ans << endl;
	return 0;
}
