#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n;

int div(vector<int> x){
	rep(i, n) if(x[i]&1 != 0) return 0;
	rep(i, n) x[i] >>= 1;
	return 1+div(x);
}

int main(void){
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ans;
	ans = div(a);
	cout << ans << endl;
	return 0;
}
