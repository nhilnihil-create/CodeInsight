#include<bits/stdc++.h>

using namespace std;

int ans = -INT_MAX, n, p[100][11];
bool f[100][10];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) for(int j = 0; j < 10; ++j) cin >> f[i][j];
	for(int i = 0; i < n; ++i) for(int j = 0; j <= 10; ++j) cin >> p[i][j];

	for(int b = 1; b < (1<<10); ++b){
		bitset<10> bit = b;
		int benefit = 0;
		for(int i = 0; i < n; ++i){
			int d = 0;
			for(int j = 0; j < 10; ++j) if(bit[9-j]&&f[i][j]) d++;
			benefit += p[i][d];
		}
		ans = max(ans, benefit);
	}

	cout << ans << endl;
}