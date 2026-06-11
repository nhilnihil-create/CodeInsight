#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;
int main(){
	int n, m;
	int ans = 0;
	bool f = 1;
	cin >> n >> m;
	vector<int> k(n);
	
	vector<vector<int>> a(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		cin >> k.at(i);
		for (int j = 0; j < k.at(i); j++) {
			int b;
			cin >> b;
			a.at(i).at(b-1) = 1;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a.at(j).at(i) == 0)f = 0;
			
		}
		if (f == 1)ans++;
		f = 1;
	}
	cout << ans << endl;
		return 0;

	
}