#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
 
 
int main() {
	int n, m;
	cin >> n >> m;
	int v[m][2];
	for (int i = 0; i < m; ++i) {
		cin >> v[i][0] >> v[i][1];
	}
	int left = v[0][0];
	int right = v[0][1];
//bool d = 1;
	for (int i = 1; i < m; ++i) {
		left = max(left,v[i][0]);
		right = min(right,v[i][1]);
	}
	cout << max(right - left + 1, 0);
}
