#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n;
	cin >> n;
	vector<int> t(n+1);
	vector<int> x(n+1);
	vector<int> y(n+1);
	for(int i = 1; i < n+1; i++) cin >> t.at(i) >> x.at(i) >> y.at(i);

	bool res = true;
	rep(i, n){
		int dt = t.at(i+1) - t.at(i);
		int dist = abs(x.at(i+1) - x.at(i) + y.at(i+1) - y.at(i));
		if(dt < dist) res = false;
		if(dt%2 != dist%2) res = false;
	}

	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;
}