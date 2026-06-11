#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, C;
	cin >> N >> C; 
	vector<vector<int>> sum(C+1, vector<int>(100000 + 2));
	for (int i = 0;i<N;++i) {
		int s, t, c;
		cin >> s >> t >> c;
		sum[c][s]++;
		sum[c][t + 1]--;
	}
	int ans = 0;
	vector<vector<int>> now(C + 1, vector<int>(100000 + 2));
	for (int i = 1;i<=100000;++i) {
		int count = 0;
		for (int j = 1;j<=C;++j) {
			now[j][i] = now[j][i-1]+sum[j][i];
			if (now[j][i]>0) {
				count++;
			}
		}
		//cout << now << endl;
		ans = max(ans,count);
	}
	cout << ans << endl;
	return 0;
}