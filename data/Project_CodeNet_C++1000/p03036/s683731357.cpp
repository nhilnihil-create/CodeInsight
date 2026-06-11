#include "bits/stdc++.h"
using namespace std;

int main() {
	int r,D,x;
	cin >> r>>D>>x;
	vector<int>Ans(11); 
	Ans[0] = x;
	for (int n = 0; n < 10; ++n) {
		Ans[n + 1] = r * Ans[n] - D;
	}	
	for (int n = 0; n < 10; ++n) {
		cout << Ans[n+1] <<endl;
	}
	return 0;
}