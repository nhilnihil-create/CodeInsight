#include <bits/stdc++.h>
#define int long long
#define INF 1e+9
using namespace std;

signed main(){
	int n,a[100000],ma = 0,b = INF;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		ma = max(ma,a[i]);
	}
	bool flag = false;
	for(int i = 0;i < n;i++){
		if(!flag && a[i] == ma) flag = true;
		else if(min(abs(b - ma / 2),abs(b - (ma + 1) / 2)) > min(abs(a[i] - ma / 2),abs(a[i] - (ma + 1) / 2))) b = a[i];
	}
	cout << ma << " " << b << endl;
	return 0;
}