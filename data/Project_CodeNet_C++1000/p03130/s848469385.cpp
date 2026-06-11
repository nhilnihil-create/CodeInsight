#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	vector<int>ans(4,0);
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		ans.at(x - 1)++;
		ans.at(y - 1)++;
	}
	sort(ans.begin(), ans.end());
	if (ans.at(3) == 2)cout << "YES" << endl;
	else cout << "NO" << endl;
	// 1,1,2,2, 1,1,1,3 
		
}