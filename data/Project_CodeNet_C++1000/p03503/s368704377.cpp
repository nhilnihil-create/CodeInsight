#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, d; cin >> N;
	vector <int> f(N); 
	vector <vector<int>> P(N, vector<int>(11));
	for (int i = 0; i < N; ++i){
		int number = 0;
		for (int j = 0; j < 10; ++j){
			cin >> d;
			if (d == 1) number += (1 << j);
		}
		f[i] = number;
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < 11; ++j) cin >> P[i][j];
	}
	int ans = -1e9-9;
	for (int i = 1; i < (1 << 10); ++i){
		int number = 0;
		for (int j = 0; j < N; ++j){
			number += P[j][__builtin_popcount(f[j] & i)];	
		}
		ans = max(ans, number);	
	}
	cout << ans << "\n";
	return 0;
}
