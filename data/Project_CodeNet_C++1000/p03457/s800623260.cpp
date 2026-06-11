#include<bits/stdc++.h>
using namespace std;

int n;

int main(void){
	cin >> n;
	vector<int> t(n+1), x(n+1), y(n+1);
	t[0] = x[0] = y[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> x[i] >> y[i];
	}
	bool f = true;
	for(int i = 0; i < n; i++){
		int dt = t[i+1]-t[i];
		int dist = abs(x[i]-x[i+1]) + abs(y[i]-y[i+1]);
		if(dist > dt) f = false;
		if(dist%2 != dt%2) f = false;
	}
	if(f) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
