#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	int n;
	cin >> n;
	int v[2][n];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
		}
	}
	int left[n];
	left[n - 1] = v[1][n - 1];
	for (int i = n - 2; i >= 0; --i) {
		left[i] = v[1][i] + left[i + 1];
	}
	int maxm = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += v[0][i];
		maxm = max(maxm, sum + left[i]);
	} 
	
	cout << maxm;
}




