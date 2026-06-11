#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main(void){
	int N; cin >> N;
	map<int, int> cnt;
	for (int i = 0; i < N; ++i){
		int Di; cin >> Di;
		cnt[Di]++;
	}
	int M; cin >> M;
	for (int i = 0; i < M; ++i){
		int Ti; cin >> Ti;
		if (cnt[Ti]-- == 0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}