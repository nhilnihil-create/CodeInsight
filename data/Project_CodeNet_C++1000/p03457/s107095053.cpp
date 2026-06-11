#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<int> t(n+1);
	vector<int> x(n+1);
	vector<int> y(n+1);
	for(int i = 1; i <= n; i++) cin >> t.at(i) >> x.at(i) >> y.at(i);

	bool can = true;
	for(int i = 0; i < n; i++){
		int dt = t.at(i+1) - t.at(i);
		int dist = abs(x.at(i+1)-x.at(i)) + abs(y.at(i+1)-y.at(i));
		if(dt < dist) can = false;
		if(dt%2 != dist%2) can = false; 
	}
	if(can) cout << "Yes" << endl;
	else cout << "No" << endl;
}