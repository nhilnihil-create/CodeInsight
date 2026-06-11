#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int n, yi, er, k;
vector<int>v[100005];
main() {
	cin >> n;
	int sq;
	sq = sqrt(n * 2);
	if(sq * (sq + 1) != n * 2) {
		puts("No");
		return 0;
	} 
	yi = 1, er = 2;
	k = sq + 1;
	int i;
	for(i = 1; i <= n; ++i) {
		v[yi].push_back(i);
		v[er].push_back(i);
		if(er < k) ++er;
		else ++yi, er = yi + 1;
	}
	puts("Yes");
	cout << k << endl;
	int j;
	for(i = 1; i <= k; ++i) {
		cout << v[i].size() << " " ;
		for(j = 0; j < v[i].size(); ++j) cout << v[i][j] << " " ;
		cout << endl;
	}
	return 0;
}