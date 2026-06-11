#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	const int MAXN = 1e5 + 1;	
	int n, m, fim[MAXN];
	vector<int> comeco[MAXN];
	cin >> n >> m;
	memset(fim, 0, (n + 1) * sizeof(int));
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		++fim[b];
		comeco[a].push_back(b);
	}
	int low = 1, high = 1, rem = 0;
	while(high < MAXN) {
		if(fim[high]) {
			++rem;
			while(low < high) {
				for(int f : comeco[low])
					--fim[f];
				++low;
			}
		}
		++high;
	}	
	cout << rem << '\n';
	return 0;
}