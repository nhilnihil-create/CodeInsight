#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N;
	cin >> N;

	vector<vector<int>> map(2, vector<int>(N));
	rep(i, 2){
		rep(n, N) cin >> map.at(i).at(n);
	}
	int Max = 0;
	rep(i, N){
		int cnt = 0;
		rep(j, i + 1) cnt += map.at(0).at(j);
		for(int k = i; k < N; k++) cnt += map.at(1).at(k);
		Max = max(Max, cnt);
	}
	cout << Max << endl;
}
