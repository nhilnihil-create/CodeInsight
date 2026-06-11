#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	int n;
	cin >> n;
	vector<int> t(n);
	vector<pair<int,int>> point(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> point[i].first >> point[i].second;
	}
	//int last = 0;
	int left = 0;
	int right = 0;
	int tt = 0;
	for (int i = 0; i < n; ++i) {
		int a = abs(left - point[i].first);
		int b =  abs(right - point[i].second);
		if (a + b  > t[i] - tt || ((a + b) % 2 != (t[i] - tt) % 2)) {
			cout << "No";
			return 0;
		}
		left = point[i].first;
		right = point[i].second;
		tt = t[i];
	}
	cout << "Yes";
}



