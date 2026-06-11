#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	long long a[n+1], l[n+1], r[n+1];
	a[0] = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(a[n] != 2){
		cout << -1 << endl;
		return 0;
	}
	l[n] = 2; r[n] = 2;
	for(int i = n; i > 0; i--){
		if(((l[i]+a[i]-1)/a[i]) * a[i] > r[i] || (r[i]/a[i]) * a[i] + a[i] - 1 < l[i]){
			cout << -1 << endl;
			return 0;
		}
		l[i-1] = ((l[i]+a[i]-1)/a[i]) * a[i];
		r[i-1] = (r[i]/a[i]) * a[i] + a[i] - 1;
	}
	cout << l[0] << " " << r[0] << endl;
	return 0;
}