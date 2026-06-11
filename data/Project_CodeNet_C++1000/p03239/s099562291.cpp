#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int N, T;
	cin >> N >> T;
	
	int minimo = 30000;
	
	for (int i = 0; i < N; i++) {
		
		int ci, ti;
		cin >> ci >> ti;
		
		if (ti <= T) minimo = min(minimo,ci);
		
	}
	
	if (minimo != 30000) cout << minimo << endl;
	else cout << "TLE" << endl;
	
}