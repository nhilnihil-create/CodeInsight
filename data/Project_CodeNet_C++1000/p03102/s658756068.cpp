#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, m, c, a;
	cin >> n >> m >> c;
	vector<int> b;
	for(int i = 0; i < m; i++) {
		cin >> a;
		b.push_back(a);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int sum = c;
		for(int i = 0; i < m; i++) {
			cin >> a;
			sum += b[i] * a;
		}
		if(sum > 0) cnt += 1;
	}
	cout << cnt;
	return 0;
}